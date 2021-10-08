import React from "react";
import { StyleSheet } from "react-native";
import { AppearanceProvider } from "react-native-appearance";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import { Provider } from "react-redux";
import store from "./redux/store";
import Routes from "./Routes";
import firebase from "firebase";
import { Root } from "native-base";

const Stack = createBottomTabNavigator();

var firebaseConfig = {
  apiKey: "AIzaSyBwieq_OGbjjjPJu5a2nYPSQQlc94wHiG8",
  authDomain: "stockmanagement-d1ddb.firebaseapp.com",
  projectId: "stockmanagement-d1ddb",
  storageBucket: "stockmanagement-d1ddb.appspot.com",
  messagingSenderId: "198375491934",
  appId: "1:198375491934:web:77a6af14491c248b7fe7cf",
  measurementId: "G-0R1FXPCEWX",
};
// Initialize Firebase
if (!firebase.apps.length) {
  firebase.initializeApp(firebaseConfig);
} else {
  firebase.app();
}

export default function App() {
  return (
    <Root>
      <Provider store={store}>
        <AppearanceProvider>
          <Routes />
        </AppearanceProvider>
      </Provider>
    </Root>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
});

// const [isDarkMode, setIsDarkMode] = useState(true);
// const MyDarkTheme = {
//   dark: true,
//   colors: {
//     primary: "#14213d",
//     background: "#000020",
//     card: "#14213D",
//     text: "#ffffff",
//     border: "#14213d",
//     notification: "#9933FF",
//   },
// };
// const MyLightTheme = {
//   dark: true,
//   colors: {
//     primary: "#d3d3d3",
//     background: "#ffffff",
//     card: "#e5383b",
//     text: "#0b090a",
//     border: "#b1a7a6",
//     notification: "#660708",
//   },
// };

// const toggleTheme = () => {
//   setIsDarkMode(!isDarkMode);
// };

// <NavigationContainer theme={isDarkMode ? MyDarkTheme : DefaultTheme}>
//           <Stack.Navigator
//             screenOptions={({ route }) => ({
//               tabBarIcon: ({ focused, color, size }) => {
//                 let iconName;

//                 if (route.name === "home") {
//                   iconName = focused ? "home-sharp" : "ios-home-outline";
//                 } else if (route.name === "addproduct") {
//                   iconName = focused ? "add-circle" : "add-circle-outline";
//                 } else if (route.name === "settings") {
//                   iconName = focused ? "ios-settings" : "ios-settings-outline";
//                 }

//                 // You can return any component that you like here!
//                 return <Ionicons name={iconName} size={size} color={color} />;
//               },
//             })}
//             tabBarOptions={{
//               activeTintColor: isDarkMode
//                 ? MyDarkTheme.colors.notification
//                 : DefaultTheme.colors.notification,
//               inactiveTintColor: isDarkMode
//                 ? MyDarkTheme.colors.text
//                 : DefaultTheme.colors.text,
//               showLabel: false,
//             }}
//             mode="modal"
//           >
//             {isAuthenticated ? (
//               <>
//                 <Stack.Screen name="home">
//                   {(props) => (
//                     <Home
//                       {...props}
//                       toggleTheme={toggleTheme}
//                       isEnabled={isDarkMode}
//                     />
//                   )}
//                 </Stack.Screen>
//                 <Stack.Screen name="addproduct" component={AddProduct} />
//                 <Stack.Screen name="settings">
//                   {(props) => (
//                     <Settings
//                       {...props}
//                       isEnabled={isDarkMode}
//                       toggleTheme={toggleTheme}
//                     />
//                   )}
//                 </Stack.Screen>
//               </>
//             ) : (
//               <>
//                 <Stack.Screen
//                   name="SignIn"
//                   component={SigninScreen}
//                   options={{ tabBarVisible: false }}
//                 />
//               </>
//             )}
//           </Stack.Navigator>
//         </NavigationContainer>
