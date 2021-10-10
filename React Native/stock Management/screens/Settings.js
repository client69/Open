import { useTheme } from "@react-navigation/native";
import {
  Body,
  Button,
  Container,
  Content,
  Header,
  Icon,
  Left,
  ListItem,
  Right,
  Title,
} from "native-base";
import React from "react";
import { StyleSheet, Text, View } from "react-native";
import { ScrollView, Switch } from "react-native-gesture-handler";
import { useSelector } from "react-redux";
import firebase from "firebase";
import { setLoggedOut } from "../redux/user/userAction";
import { useDispatch } from "react-redux";

export default function Settings({ navigation, toggleTheme, isEnabled }) {
  const { colors } = useTheme();
  const user = useSelector((state) => state.user);
  const dispatch = useDispatch();

  return (
    <ScrollView style={{ ...styles.container }}>
      <Header
        style={{
          backgroundColor: colors.notification,
          display: "flex",
          justifyContent: "center",
          alignItems: "center",
        }}
      >
        <Title>Settings</Title>
      </Header>
      <Container
        style={{
          backgroundColor: "transparent",
          padding: 0,
          margin: 0,
          height: "100%",
        }}
      >
        <Content>
          <ListItem icon>
            <Body>
              <Text style={{ color: colors.text }}>Theme</Text>
            </Body>
            <Right>
              <Switch
                trackColor={{ false: "#767577", true: "#81b0ff" }}
                thumbColor={isEnabled ? "#f5dd4b" : "#f4f3f4"}
                ios_backgroundColor="#3e3e3e"
                onValueChange={toggleTheme}
                value={isEnabled}
              />
              <Icon
                active
                name={isEnabled ? "md-moon-sharp" : "md-sunny-sharp"}
                style={{ color: isEnabled ? "#f4f3f4" : "#f5dd4b" }}
              />
            </Right>
          </ListItem>
          <ListItem icon>
            <Left>
              <Icon
                active
                type="FontAwesome"
                name="user"
                style={{ color: colors.text }}
              />
            </Left>
            <Body>
              <Text style={{ color: colors.text }}>Company Name:</Text>
            </Body>
            <Right>
              <Text
                style={{
                  color: colors.text,
                }}
              >
                {user.companyName}
              </Text>
            </Right>
          </ListItem>
          <ListItem icon>
            <Left>
              <Icon
                active
                name="alternate-email"
                type="MaterialIcons"
                style={{ color: colors.text }}
              />
            </Left>
            <Body>
              <Text style={{ color: colors.text }}>Email:</Text>
            </Body>
            <Right>
              <Text
                style={{
                  color: colors.text,
                }}
              >
                {user.email}
              </Text>
            </Right>
          </ListItem>
          <Button
            full
            danger
            style={{ marginTop: 9 }}
            onPress={(e) => {
              firebase
                .auth()
                .signOut()
                .then(() => {
                  dispatch(setLoggedOut());
                  navigation.navigate("SignIn");
                })
                .catch((err) => alert(err.message));
            }}
          >
            <Text>Log Out</Text>
          </Button>
        </Content>
      </Container>
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
