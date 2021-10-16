import { DefaultTheme, NavigationContainer } from "@react-navigation/native";
import React, { useEffect, useState } from "react";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import Home from "./screens/Home";
import AddProduct from "./screens/AddProduct";
import Ionicons from "react-native-vector-icons/Ionicons";
import Settings from "./screens/Settings";
import SigninScreen from "./screens/Authentication/SignInScreen";
import { useSelector } from "react-redux";
import SignUpScreen from "./screens/Authentication/SignUpScreen";
import { useDispatch } from "react-redux";
import firebase from "firebase";
import { setLoggedIn } from "./redux/user/userAction";
import AsyncStorage from "@react-native-community/async-storage";
import * as Font from "expo-font";
const Stack = createBottomTabNavigator();

const Routes = () => {
  const [isDarkMode, setIsDarkMode] = useState(true);
  const [isLoaded, setIsLoaded] = useState(false);
  const isAuthenticated = useSelector((state) => state.user.isAuthenticated);
  const dispatch = useDispatch();
  const MyDarkTheme = {
    dark: true,
    colors: {
      primary: "#14213d",
      background: "#000020",
      card: "#14213D",
      text: "#ffffff",
      border: "#14213d",
      notification: "#9933FF",
      productCard: "#242B2E",
      activeButton: "#51E1ED",
    },
  };
  const MyLightTheme = {
    dark: true,
    colors: {
      ...DefaultTheme.colors,
      card: "#fff",
      productCard: "#e9ecef",
      activeButton: "#F4CE6A",
    },
  };

  useEffect(() => {
    firebase.auth().onAuthStateChanged((user) => {
      if (user) {
        dispatch(setLoggedIn(user.uid, user.displayName, user.email));
      }
      setIsLoaded(true);
    });
    (async () => {
      let theme = await AsyncStorage.getItem("theme");
      if (!theme) {
        setIsDarkMode(true);
        await AsyncStorage.setItem("theme", "dark");
      }
      if (theme === "dark") {
        setIsDarkMode(true);
      } else {
        setIsDarkMode(false);
      }
    })();
    (async () => {
      await Font.loadAsync({
        Roboto: require("native-base/Fonts/Roboto.ttf"),
        Roboto_medium: require("native-base/Fonts/Roboto_medium.ttf"),
      });
    })();
  }, []);

  const toggleTheme = async () => {
    if (isDarkMode) {
      await AsyncStorage.setItem("theme", "light");
    } else {
      await AsyncStorage.setItem("theme", "dark");
    }
    setIsDarkMode(!isDarkMode);
  };

  return (
    <NavigationContainer theme={isDarkMode ? MyDarkTheme : MyLightTheme}>
      {isLoaded && (
        <Stack.Navigator
          screenOptions={({ route }) => ({
            tabBarIcon: ({ focused, color, size }) => {
              let iconName;

              if (route.name === "home") {
                iconName = focused ? "home-sharp" : "ios-home-outline";
              } else if (route.name === "addproduct") {
                iconName = focused ? "add-circle" : "add-circle-outline";
              } else if (route.name === "settings") {
                iconName = focused ? "ios-settings" : "ios-settings-outline";
              }

              // You can return any component that you like here!
              return <Ionicons name={iconName} size={size} color={color} />;
            },
          })}
          tabBarOptions={{
            activeTintColor: isDarkMode
              ? MyDarkTheme.colors.notification
              : DefaultTheme.colors.notification,
            inactiveTintColor: isDarkMode
              ? MyDarkTheme.colors.text
              : DefaultTheme.colors.text,
            showLabel: false,
          }}
          mode="modal"
        >
          {isAuthenticated ? (
            <>
              <Stack.Screen name="home">
                {(props) => (
                  <Home
                    {...props}
                    toggleTheme={toggleTheme}
                    isEnabled={isDarkMode}
                  />
                )}
              </Stack.Screen>
              <Stack.Screen name="addproduct" component={AddProduct} />
              <Stack.Screen name="settings">
                {(props) => (
                  <Settings
                    {...props}
                    isEnabled={isDarkMode}
                    toggleTheme={toggleTheme}
                  />
                )}
              </Stack.Screen>
            </>
          ) : (
            <>
              <Stack.Screen
                name="SignIn"
                component={SigninScreen}
                options={{ tabBarVisible: false }}
              />
              <Stack.Screen
                name="SignUp"
                component={SignUpScreen}
                options={{ tabBarVisible: false }}
              />
            </>
          )}
        </Stack.Navigator>
      )}
    </NavigationContainer>
  );
};

export default Routes;
