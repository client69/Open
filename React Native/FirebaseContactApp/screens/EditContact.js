import React, { Component, useState, useEffect } from "react";

import {
  View,
  StyleSheet,
  Text,
  TouchableWithoutFeedback,
  Keyboard,
  KeyboardAvoidingView,
  Image,
  TouchableOpacity,
  ActivityIndicator,
  ScrollView
} from "react-native";

//TODO: Add UUID
import uuid from 'react-native-uuid';

import * as ImagePicker from 'expo-image-picker';

import { Form, Item, Input, Label, Button } from "native-base";


//TODO: add firebase
import * as firebase from 'firebase'
import { Header } from "react-native/Libraries/NewAppScreen";

export default function EditContact({route,navigation}){ 
  

  const [state,setState] = useState({
      fname: "",
      lname: "",
      phone: "",
      email: "",
      address: "",
      image: "empty",
      imageDownloadUrl: "empty",
      isUploading: false,
      isLoading: true,
      key: ""
  }) 

  useEffect(() => {
    var key = route.params.key
    getContact(key)
  }, [])

  //TODO: getContact  method
  const getContact = async (key) => {
    let contactRef = firebase.database().ref().child(key)
    await contactRef.on("value",dataSnapshot => {
      if(dataSnapshot.val()){
        let contactVal = dataSnapshot.val()
        setState({
          ...state,
          fname:contactVal.fname,
          lname:contactVal.lname,
          phone:contactVal.phone,
          email:contactVal.email,
          address:contactVal.address,
          image:contactVal.image,
          isLoading:false,
          key:key
        })
      }
    })
  };

  //TODO: update contact method
  const updateContact = async key => {
    if(
      state.fname !== "" &&
      state.lname !== "" &&
      state.phone !== "" &&
      state.email !== "" &&
      state.address !== "" 
    ){
      setState({...state,isUploading:true})
      const dbReference = firebase.database().ref()
      const storageRef = firebase.storage().ref()
      var url = "empty"
      if(state.image !== "empty"){
        const downloadUrl = await uploadImageAsync(state.image, storageRef)
        url = downloadUrl
      }

      var contact = {
        fname:state.fname,
        lname:state.lname,
        phone:state.phone,
        email:state.email,
        address:state.address,
        imageUrl:url,
      }
      await dbReference.child(key).set(contact,err => {
        if(!err){
          route.params.getContact()
          navigation.goBack();
        }
      })
    }

  };

  //TODO: pick image from gallery
  const pickImage = async () => {
    let result = await ImagePicker.launchImageLibraryAsync({
      quality:0.2,
      base64:true,
      allowsEditing:true,
      aspect:[1,1]
    })
    if(!result.cancelled){
      setState({...state, image:result.uri})
    }
  };

  //TODO: upload to firebase
  const uploadImageAsync = async (uri, storageRef) => {
    const parts = uri.split(".")
    const fileExtension = parts[parts.length - 1]

    //creating blob
    const blob = await new Promise((resolve,reject) => {
      const xhr = new XMLHttpRequest();
      xhr.onload = function(){
        resolve(xhr.response)
      };
      xhr.onerror = function(e){
        console.log(e)
        reject(new TypeError("Network Request Failed"))
      };
      xhr.responseType = "blob"
      xhr.open("GET",uri,true)
      xhr.send(null)      
    })
    //send to firebase
    const ref = storageRef.child("ContactImages").child(uuid.v4() + "." + fileExtension)
    const snapshot = await ref.put(blob)

    //close blob
    blob.close()
    return await snapshot.ref.getDownloadURL
  };

  // render method  
    if (state.isUploading) {
      return (
        <View
          style={{ flex: 1, alignContent: "center", justifyContent: "center" }}
        >
          <ActivityIndicator size="large" color="#B83227" />
          <Text style={{ textAlign: "center" }}>
            Contact Updateing please wait..
          </Text>
        </View>
      );
    }
    return (
      <ScrollView        
        style={{ flex: 1 }}        
      >
        <TouchableWithoutFeedback
          onPress={() => {
            // dismiss the keyboard if touch any other area then input
            Keyboard.dismiss();
          }}
        >
          <ScrollView style={styles.container}>
            <TouchableOpacity
              onPress={() => {
                pickImage();
              }}
            >
              <Image
                source={
                  state.image === "empty"
                    ? require("../assets/person.png")
                    : {
                        uri: state.image
                      }
                }
                style={styles.imagePicker}
              />
            </TouchableOpacity>
            <Form>
              <Item style={styles.inputItem} floatingLabel>
                <Label>First Name</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="default"
                  onChangeText={fname => setState({...state, fname })}
                  value={
                    // set current contact value to input box
                    state.fname
                  }
                />
              </Item>
              <Item style={styles.inputItem} floatingLabel>
                <Label>Last Name</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="default"
                  onChangeText={lname => setState({...state, lname })}
                  value={state.lname}
                />
              </Item>
              <Item style={styles.inputItem} floatingLabel>
                <Label>Phone</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="number-pad"
                  onChangeText={phone => setState({...state, phone })}
                  value={state.phone}
                />
              </Item>
              <Item style={styles.inputItem} floatingLabel>
                <Label>Email</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="email-address"
                  onChangeText={email => setState({...state, email })}
                  value={state.email}
                />
              </Item>
              <Item style={styles.inputItem} floatingLabel>
                <Label>Address</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="default"
                  onChangeText={address => setState({...state, address })}
                  value={state.address}
                />
              </Item>
            </Form>

            <Button
              style={styles.button}
              full
              rounded
              onPress={() => {
                updateContact(state.key);
              }}
            >
              <Text style={styles.buttonText}>Update</Text>
            </Button>
          </ScrollView>
        </TouchableWithoutFeedback>
      </ScrollView>
    );
  }
// styles
const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    margin: 10
  },
  inputItem: {
    margin: 10
  },
  imagePicker: {
    justifyContent: "center",
    alignSelf: "center",
    width: 100,
    height: 100,
    borderRadius: 100,
    borderColor: "#c1c1c1",
    borderWidth: 2
  },
  button: {
    backgroundColor: "#B83227",
    marginTop: 40
  },
  buttonText: {
    color: "#fff",
    fontWeight: "bold"
  }
});
