import React, { Component, useState, useEffect } from "react";
import {
  View,
  Text,
  StyleSheet,
  TouchableOpacity,
  ScrollView,
  Linking,
  Alert,
  Platform,
  ActivityIndicator,
  Image,
  Dimensions
} from "react-native";
import { Card, CardItem } from "native-base";
import { Entypo } from "@expo/vector-icons";

//TODO: add firebase
import * as firebase from 'firebase'

export default function ViewContact({route,navigation}){
  const [state,setState] = useState({
      fname: null,
      lname: null,
      phone: null,
      email: null,
      address: null,
      imageUrl: null,
      key: null,
      isLoading: true
  })

  // lifecycle method  

  useEffect(() => {
    var key = route.params.key
    getContact(key)
  }, [])

  //TODO: get contact from firebase
  const getContact = async (key) => {
    let contactRef = firebase.database().ref().child(key) 
    await contactRef.on("value", dataSnapshot => {
      if(dataSnapshot.val()){
        contactVal = dataSnapshot.val()
        setState({
          ...state,
          fname:contactVal.fname,
          lname:contactVal.lname,
          phone:contactVal.phone,
          email:contactVal.email,
          address:contactVal.address,
          imageUrl:contactVal.imageUrl,
          key: key,
          isLoading:false
        })
      }
    })
  };

  //This was already explained in AsyncStorage section
  const callAction = phone => {
    let phoneNumber = phone;
    if(Platform.OS !== "android"){
      phoneNumber = `telpromt:${phone}`
    }else{
      phoneNumber = `tel:${phone}`
    }
    Linking.canOpenURL(phoneNumber)
    .then( supported => {
      if(!supported){
        Alert.alert("Phone number is not available")
      }else{
        return Linking.openURL(phoneNumber)
      }
    })
    .catch(err => console.log(err))
  }
  //This was already explained in AsyncStorage section
  // sms action
  const smsAction = phone => {
    let phoneNumber = phone;
    phoneNumber = `sms:${phone}`
    Linking.canOpenURL(phoneNumber)
    .then( supported => {
      if(!supported){
        Alert.alert("Phone number is not available")
      }else{
        return Linking.openURL(phoneNumber)
      }
    })
    .catch(err => console.log(err))
  }

  //TODO:  deleteContact method
  const deleteContact = key => {
    Alert.alert(
      "Delete Contact",
      `${state.fname} ${state.lname}`,
      [
        {text:"Cancel", onPress: () => console.log("Cancelled Press")},
        {text:"OK", onPress: async () => {
          let contactRef = firebase.database().ref().child(key);
          await contactRef.remove(err => {
            if(!err){
              route.params.getAllContact()
              navigation.goBack()
            }
          })
        } 
      },
      ],
      {cancelable: false}
    )
  };

  // editContact function
  const editContact = key => {
    navigation.navigate("Edit",{key: key, getContact})
  }

  // render method  
    // if loading show ActivityIndicator
    if (state.isLoading) {
      return (
        <View
          style={{
            flex: 1,
            alignContent: "center",
            justifyContent: "center"
          }}
        >
          <ActivityIndicator size="large" color="#B83227" />
          <Text style={{ textAlign: "center" }}>
            Contact loading please wait..
          </Text>
        </View>
      );
    }
    // else show contact details
    return (
      <ScrollView style={styles.container}>
        <View style={styles.contactIconContainer}>
          <Image
            style={styles.contactIcon}
            source={
              state.imageUrl === "empty"
                ? require("../assets/person.png")
                : {
                    uri: state.imageUrl
                  }
            }
          />
          <View style={styles.nameContainer}>
            <Text style={styles.name}>
              {state.fname} {state.lname}
            </Text>
          </View>
        </View>
        <View style={styles.infoContainer}>
          <Card>
            <CardItem bordered>
              <Text style={styles.infoText}>Phone</Text>
            </CardItem>
            <CardItem bordered>
              <Text style={styles.infoText}>{state.phone}</Text>
            </CardItem>
          </Card>
          <Card>
            <CardItem bordered>
              <Text style={styles.infoText}>Email</Text>
            </CardItem>
            <CardItem bordered>
              <Text style={styles.infoText}>{state.email}</Text>
            </CardItem>
          </Card>
          <Card>
            <CardItem bordered>
              <Text style={styles.infoText}>Address</Text>
            </CardItem>
            <CardItem bordered>
              <Text style={styles.infoText}>{state.address}</Text>
            </CardItem>
          </Card>
        </View>
        <Card style={styles.actionContainer}>
          <CardItem style={styles.actionButton} bordered>
            <TouchableOpacity
              onPress={() => {
                smsAction(state.phone);
              }}
            >
              <Entypo name="message" size={50} color="#B83227" />
            </TouchableOpacity>
          </CardItem>
          <CardItem style={styles.actionButton} bordered>
            <TouchableOpacity
              onPress={() => {
                callAction(state.phone);
              }}
            >
              <Entypo name="phone" size={50} color="#B83227" />
            </TouchableOpacity>
          </CardItem>
        </Card>

        <Card style={styles.actionContainer}>
          <CardItem style={styles.actionButton} bordered>
            <TouchableOpacity
              onPress={() => {
                editContact(state.key);
              }}
            >
              <Entypo name="edit" size={30} color="#B83227" />
              <Text style={styles.actionText}>Edit</Text>
            </TouchableOpacity>
          </CardItem>
          <CardItem style={styles.actionButton} bordered>
            <TouchableOpacity
              onPress={() => {
                deleteContact(state.key);
              }}
            >
              <Entypo name="trash" size={30} color="#B83227" />
              <Text style={styles.actionText}>Delete</Text>
            </TouchableOpacity>
          </CardItem>
        </Card>
      </ScrollView>
    );
  }
// styles
const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff"
  },
  contactIconContainer: {
    alignItems: "center",
    justifyContent: "center"
  },
  contactIcon: {
    // to create a square box both height and width should be same
    height: Dimensions.get("window").width,
    width: Dimensions.get("window").width
  },
  nameContainer: {
    width: "100%",
    height: 70,
    padding: 10,
    backgroundColor: "rgba(255,255,255,0.5)",
    justifyContent: "center",
    position: "absolute",
    bottom: 0
  },
  name: {
    fontSize: 24,
    color: "#000",
    fontWeight: "900"
  },
  infoText: {
    fontSize: 18,
    fontWeight: "300"
  },
  actionContainer: {
    flexDirection: "row"
  },
  actionButton: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center"
  },
  actionText: {
    color: "#B83227",
    fontWeight: "900"
  }
});
