import React, { useState } from "react";
import {
  StyleSheet,
  Text,
  View,
  TouchableOpacity,
  Image,
  ScrollView,
  ActivityIndicator,
} from "react-native";
import firebase from "firebase";
import {
  Form,
  Item,
  Input,
  Label,
  Button,
  Icon,
  Textarea,
  Container,
  ListItem,
  Left,
  Body,
  Right,
  Toast,
} from "native-base";
import { useTheme } from "@react-navigation/native";
import { useDispatch } from "react-redux";
import * as ImagePicker from "expo-image-picker";
import { useSelector } from "react-redux";
import { v4 } from "react-native-uuid";
import { fetchProducts } from "../redux/product/productAction";

export default function AddProduct({ navigation }) {
  const { colors } = useTheme();
  const [data, setData] = useState({
    productName: "",
    uri: null,
    quantity: "",
    description: "",
    productId: "",
  });
  const [isUploading, setIsUploading] = useState(false);
  const user = useSelector((state) => state.user);
  const loading = useSelector((state) => state.products.loading);
  const dispatch = useDispatch();

  const openPicker = async () => {
    let permissionResult =
      await ImagePicker.requestMediaLibraryPermissionsAsync();

    if (permissionResult.granted === false) {
      alert("Permission to access camera roll is required!");
      return;
    }

    let pickerResult = await ImagePicker.launchImageLibraryAsync({
      quality: 0.2,
      base64: true,
      allowsEditing: true,
    });
    // console.log(pickerResult);
    setData({
      ...data,
      uri: pickerResult.uri,
    });
  };
  const openCamera = async () => {
    let permissionResult =
      await ImagePicker.requestMediaLibraryPermissionsAsync();

    if (permissionResult.granted === false) {
      alert("Permission to access camera roll is required!");
      return;
    }

    let pickerResult = await ImagePicker.launchCameraAsync({
      quality: 0.2,
      base64: true,
      allowsEditing: true,
    });
    // console.log(pickerResult);
    setData({
      ...data,
      uri: pickerResult.uri,
    });
  };

  const uploadImageAsync = async (uri, storageRef, imageName) => {
    const parts = uri.split(".");
    const fileExtension = parts[parts.length - 1];

    //create blob

    const blob = await new Promise((resolve, reject) => {
      const xhr = new XMLHttpRequest();
      xhr.onload = function () {
        resolve(xhr.response);
      };

      xhr.onerror = function (e) {
        console.log(e);
        reject(new TypeError("Network Request Failed"));
      };
      xhr.responseType = "blob";
      xhr.open("GET", uri, true);
      xhr.send(null);
    });

    //upload
    const ref = storageRef
      .child("productImages")
      .child(user.userId)
      .child(imageName + "." + fileExtension);
    const snapshot = await ref.put(blob);

    //close blob
    blob.close();
    let url = await snapshot.ref.getDownloadURL();
    return { url, fileExtension };
  };

  const saveProduct = async () => {
    let { description, productId, productName, quantity, uri } = data;
    if (
      description !== "" &&
      productId !== "" &&
      productName !== "" &&
      quantity !== "" &&
      uri !== null
    ) {
      setIsUploading(true);

      const fileName = v4();
      const storageRef = firebase.storage().ref();
      const docName = v4();
      const dbRef = firebase.firestore().collection(user.userId).doc(docName);
      const { url, fileExtension } = await uploadImageAsync(
        uri,
        storageRef,
        fileName
      );
      let obj = {
        productId,
        description,
        productName,
        quantity,
        downloadUrl: url,
        fileName,
        docName,
        fileExtension,
        createdAt: firebase.firestore.FieldValue.serverTimestamp(),
      };
      dbRef
        .set(Object.assign({}, obj))
        .then(() => {
          setData({
            ...data,
            description: "",
            productId: "",
            productName: "",
            quantity: "",
            uri: null,
          });
          Toast.show({
            text: "Product Added Successfully",
            swipeDisabled: false,
            type: "success",
          });
          setIsUploading(false);
          fetchProducts(dispatch, user.userId);
          navigation.navigate("home");
        })
        .catch((err) => {
          console.error(err);
        });
    } else {
      Toast.show({
        text: "All Fields are required",
        buttonText: "Ok",
        type: "danger",
        duration: 3000,
        swipeDisabled: false,
      });
    }
  };

  return (
    <ScrollView style={styles.container}>
      <View style={styles.logoContainer}>
        {/* <Image source={require("../assets/logo.png")} /> */}
        <Text style={{ color: colors.text, fontSize: 30 }}>Add Product</Text>
      </View>
      <View style={{ flex: 1 }}>
        <Form style={{ ...styles.form, flex: 1, overflow: "scroll" }}>
          <Item floatingLabel>
            <Label style={{ color: colors.text, fontSize: 12 }}>
              Product Name
            </Label>
            <Input
              autoCorrect={false}
              autoCapitalize="none"
              keyboardType="name-phone-pad"
              onChangeText={(productName) => setData({ ...data, productName })}
              value={data.productName}
              style={{ color: colors.text }}
            />
          </Item>
          <Item floatingLabel>
            <Label style={{ color: colors.text, fontSize: 12 }}>
              Product ID
            </Label>
            <Input
              autoCorrect={false}
              autoCapitalize="none"
              keyboardType="name-phone-pad"
              onChangeText={(productId) => setData({ ...data, productId })}
              value={data.productId}
              style={{ color: colors.text }}
            />
          </Item>
          <Item floatingLabel>
            <Label style={{ color: colors.text, fontSize: 12 }}>Quantity</Label>
            <Input
              autoCorrect={false}
              autoCapitalize="none"
              keyboardType="name-phone-pad"
              onChangeText={(quantity) => setData({ ...data, quantity })}
              value={data.quantity}
              style={{ color: colors.text }}
            />
          </Item>
          <View
            style={{
              borderBottomColor: colors.text,
              borderBottomWidth: 1,
              marginTop: 40,
              marginLeft: 15,
            }}
          >
            <Label style={{ color: colors.text, fontSize: 12 }}>
              Product Description
            </Label>
            <Textarea
              autoCorrect={false}
              autoCapitalize="none"
              keyboardType="name-phone-pad"
              onChangeText={(description) => setData({ ...data, description })}
              value={data.description}
              style={{ color: colors.text, width: "100%" }}
              rowSpan={2}
            />
          </View>
          {data.uri ? (
            <View style={{ marginTop: 30 }}>
              <Image
                source={{
                  uri: data.uri,
                }}
                style={styles.imagePicker}
              />
              <ListItem icon style={{ marginTop: 20 }}>
                <Left>
                  <Icon
                    active
                    type="MaterialCommunityIcons"
                    name="file-upload-outline"
                    style={{ color: colors.text }}
                  />
                </Left>
                <Body>
                  <Text style={{ color: colors.text }}>Product Image</Text>
                </Body>
                <Right>
                  <TouchableOpacity
                    onPress={() => {
                      setData({
                        ...data,
                        uri: null,
                        base64: null,
                        fileType: null,
                      });
                    }}
                  >
                    <Icon
                      active
                      type="Entypo"
                      name="cross"
                      style={{ color: "#fc0303" }}
                    />
                  </TouchableOpacity>
                </Right>
              </ListItem>
            </View>
          ) : (
            <View>
              <Button
                style={{
                  ...styles.button,
                  backgroundColor: colors.notification,
                }}
                full
                rounded
                onPress={() => {
                  openCamera();
                }}
              >
                <Icon name="camera" type="Entypo" />
                <Text style={{ ...styles.buttonText }}>Open Camera</Text>
              </Button>
              <View
                style={{
                  width: "100%",
                  display: "flex",
                  justifyContent: "center",
                  alignItems: "center",
                  marginTop: 25,
                }}
              >
                <Text style={{ color: colors.text }}>OR</Text>
              </View>
              <Button
                style={{
                  ...styles.button,
                  backgroundColor: colors.notification,
                }}
                full
                rounded
                onPress={() => {
                  openPicker();
                }}
              >
                <Icon
                  name="file-upload-outline"
                  type="MaterialCommunityIcons"
                />
                <Text style={{ ...styles.buttonText }}>Choose File</Text>
              </Button>
            </View>
          )}

          <Button
            style={styles.button}
            full
            rounded
            onPress={() => {
              saveProduct();
            }}
          >
            {isUploading ? (
              <ActivityIndicator size="small" color={colors.text} />
            ) : (
              <Text style={{ ...styles.buttonText }}>Add Product</Text>
            )}
          </Button>
        </Form>
      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  logoContainer: {
    alignItems: "center",
    marginTop: 100,
    marginBottom: 100,
  },
  form: {
    padding: 20,
    width: "100%",
  },
  button: {
    marginTop: 20,
  },
  buttonText: {
    color: "#fff",
  },
  footer: {
    alignItems: "center",
  },
  goBack: {
    borderWidth: 2,
    borderRadius: 5,
  },
  imagePicker: {
    justifyContent: "center",
    alignSelf: "center",
    width: 100,
    height: 100,
    borderRadius: 20,
    borderColor: "#c1c1c1",
    borderWidth: 2,
  },
});
