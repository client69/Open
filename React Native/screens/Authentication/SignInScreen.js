import React, { useState } from "react";
import { StyleSheet, Text, View, TouchableOpacity } from "react-native";
import firebase from "firebase";
import { Form, Item, Input, Label, Button, Icon } from "native-base";
import { ScrollView } from "react-native-gesture-handler";
import { useTheme } from "@react-navigation/native";
import { useDispatch } from "react-redux";
import { setLoggedIn } from "../../redux/user/userAction";

export default function SigninScreen({ route, navigation }) {
  const [data, setData] = useState({
    email: "",
    password: "",
  });
  const [isPasswordVisible, setIsPasswordVisible] = useState(false);
  const { colors } = useTheme();
  const dispatch = useDispatch();

  const signUserIn = () => {
    firebase.auth().setPersistence(firebase.auth.Auth.Persistence.LOCAL);
    firebase
      .auth()
      .signInWithEmailAndPassword(data.email, data.password)
      .then((res) => {
        dispatch(
          setLoggedIn(res.user.uid, res.user.displayName, res.user.email)
        );
        navigation.navigate("home");
      })
      .catch((err) => alert(err.message));
  };

  return (
    <ScrollView style={styles.container} keyboardShouldPersistTaps="always">
      <View style={styles.logoContainer}>
        {/* <Image source={require("../assets/logo.png")} /> */}
        <Text style={{ color: colors.text, fontSize: 30 }}>Sign In</Text>
      </View>
      <Form style={styles.form}>
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
        <Button style={styles.button} full rounded onPress={signUserIn}>
          <Text style={styles.buttonText}>Sign in</Text>
        </Button>
      </Form>
      <View style={{ ...styles.footer }}>
        <Text style={{ color: colors.text }}>OR</Text>
        <TouchableOpacity
          onPress={() => {
            navigation.navigate("SignUp");
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
            <Text style={{ color: colors.text }}>Create a new Account</Text>
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
    marginTop: 200,
    marginBottom: 50,
  },
  form: {
    padding: 20,
    width: "100%",
    marginBottom: 10,
  },
  button: {
    marginTop: 20,
  },
  buttonText: {
    color: "#fff",
  },
  footer: {
    alignItems: "center",
    marginBottom: 20,
  },
  goBack: {
    borderWidth: 2,
    borderRadius: 5,
  },
});
