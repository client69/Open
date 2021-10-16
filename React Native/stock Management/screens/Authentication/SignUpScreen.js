import React, { useState } from "react";
import { StyleSheet, Text, View, TouchableOpacity, Image } from "react-native";
import { ScrollView } from "react-native-gesture-handler";
import firebase from "firebase";
import { Form, Item, Input, Label, Button, Icon } from "native-base";
import { useTheme } from "@react-navigation/native";
import { useDispatch } from "react-redux";
import { setLoggedIn } from "../../redux/user/userAction";

export default function SignUpScreen({ route, navigation }) {
  const [data, setData] = useState({
    email: "",
    password: "",
    companyName: "",
  });
  const [isPasswordVisible, setIsPasswordVisible] = useState(false);
  const { colors } = useTheme();
  const dispatch = useDispatch();
  const signUserUp = () => {
    let { email, password, companyName } = data;
    if (email !== "" && password !== "" && companyName !== "") {
      firebase.auth().setPersistence(firebase.auth.Auth.Persistence.LOCAL);
      firebase
        .auth()
        .createUserWithEmailAndPassword(email, password)
        .then((authenticate) => {
          let uid = authenticate.user.uid;
          authenticate.user
            .updateProfile({
              displayName: companyName,
            })
            .then(() => {
              dispatch(setLoggedIn(uid, companyName, email));
              navigation.navigate("home");
            })
            .catch((err) => alert(err.message));
        })
        .catch((err) => {
          alert(err.message);
        });
    }
  };

  return (
    <ScrollView style={styles.container} keyboardShouldPersistTaps="always">
      <View style={styles.logoContainer}>
        {/* <Image source={require("../assets/logo.png")} /> */}
        <Text style={{ color: colors.text, fontSize: 30 }}>Register</Text>
      </View>
      <Form style={styles.form}>
        <Item floatingLabel>
          <Label style={{ color: colors.text, fontSize: 12 }}>
            Company Name
          </Label>
          <Input
            autoCorrect={false}
            autoCapitalize="none"
            keyboardType="name-phone-pad"
            onChangeText={(companyName) => setData({ ...data, companyName })}
            style={{ color: colors.text }}
          />
        </Item>
        <Item floatingLabel>
          <Label style={{ color: colors.text, fontSize: 12 }}>Email</Label>
          <Input
            autoCorrect={false}
            autoCapitalize="none"
            keyboardType="name-phone-pad"
            onChangeText={(email) => setData({ ...data, email })}
            style={{ color: colors.text }}
          />
        </Item>
        <Item floatingLabel>
          <Label style={{ color: colors.text, fontSize: 12 }}>Password</Label>
          <Input
            secureTextEntry={!isPasswordVisible}
            autoCorrect={false}
            autoCapitalize="none"
            keyboardType="name-phone-pad"
            onChangeText={(password) => setData({ ...data, password })}
            style={{ color: colors.text }}
          />
          <Icon
            style={{ color: colors.text }}
            active
            name={isPasswordVisible ? "eye-outline" : "eye-off-outline"}
            onPress={() => {
              setIsPasswordVisible(!isPasswordVisible);
            }}
          />
        </Item>
        <Button
          style={styles.button}
          full
          rounded
          onPress={() => {
            signUserUp();
          }}
        >
          <Text style={{ ...styles.buttonText }}>Create Account</Text>
        </Button>
      </Form>
      <View style={styles.footer}>
        <Text>OR</Text>
        <TouchableOpacity
          onPress={() => {
            navigation.navigate("SignIn");
          }}
        >
          <View
            style={{
              ...styles.goBack,
              backgroundColor: colors.card,
              borderColor: colors.border,
              padding: 3,
            }}
          >
            <Text style={{ color: colors.text }}>Alredy have an Account?</Text>
          </View>
        </TouchableOpacity>
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
});
