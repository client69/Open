import React, { Component, useState } from "react";
import {
  View,
  StyleSheet,
  Text,
  TouchableWithoutFeedback,
  TouchableOpacity,
  Keyboard,
  KeyboardAvoidingView,
  ScrollView,
  ActivityIndicator,
  Image
} from "react-native";
import * as firebase from 'firebase'
//TODO: Read about UUID
import uuid from 'react-native-uuid';

import { Form, Item, Input, Label, Button } from "native-base";

import * as ImagePicker from 'expo-image-picker';
import { Header } from "react-native/Libraries/NewAppScreen";

//TODO: add firebase

export default function AddNewContact({route,navigation}){  
  //TODO: create constructor with state: fname, lname, phone, email, address, image, imageDownloadUrl, isUploading

  const [state,setState] = useState({
    fname:"",
    lname:"",
    phone:"",
    email:"",
    address:"",
    image:"empty",    
    isUploading:false
  })
  const [imageDownloadUrl,setImageDownloadUrl] = useState("empty")

  //TODO: savecontact method
  const saveContact = async () => {
    // create and save contact to firebase
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

      //save all values to an object

      var contact = {
        fname: state.fname,
        lname: state.lname,
        phone: state.phone,
        email: state.email,
        address: state.address,
        imageUrl: url
      }
      await dbReference.push(contact, err => {
        if(!err){
          route.params.getAllContact()
          navigation.goBack()
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

  //TODO: upload image to firebase
  const uploadImageAsync = async (uri, storageRef) => {
    const parts = uri.split(".");
    const fileExtension = parts[parts.length - 1]

    //create blob

    const blob = await new Promise( (resolve, reject) => {
      const xhr = new XMLHttpRequest();
      xhr.onload = function(){
        resolve(xhr.response)
      }

      xhr.onerror = function(e){
        console.log(e)
        reject(new TypeError("Network Request Failed"))
      }
      xhr.responseType = "blob";
      xhr.open("GET",uri,true)
      xhr.send(null)
    } )

    //upload    
    const ref = storageRef
    .child("ContactImages")
    .child(uuid.v4() + "." + fileExtension)
    const snapshot = await ref.put(blob)    

    //close blob
    blob.close()
    return await snapshot.ref.getDownloadURL()

  };

  //render method  
    if (state.isUploading) {
      return (
        <View
          style={{ flex: 1, alignContent: "center", justifyContent: "center" }}
        >
          <ActivityIndicator size="large" color="#B83227" />
          <Text style={{ textAlign: "center" }}>
            Contact Uploading please wait..
          </Text>
        </View>
      );
    }
    return (
      // <KeyboardAvoidingView
      //   keyboardVerticalOffset={Header.HEIGHT + 20} // adjust the value here if you need more padding
      //   style={{ flex: 1 }}
      //   behavior="padding"
      // >
      <ScrollView style={{flex:1}}>
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
                />
              </Item>
              <Item style={styles.inputItem} floatingLabel>
                <Label>Last Name</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="default"
                  onChangeText={lname => setState({...state, lname })}
                />
              </Item>
              <Item style={styles.inputItem} floatingLabel>
                <Label>Phone</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="number-pad"
                  onChangeText={phone => setState({...state, phone })}
                />
              </Item>
              <Item style={styles.inputItem} floatingLabel>
                <Label>Email</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="email-address"
                  onChangeText={email => setState({...state, email })}
                />
              </Item>
              <Item style={styles.inputItem} floatingLabel>
                <Label>Address</Label>
                <Input
                  autoCorrect={false}
                  autoCapitalize="none"
                  keyboardType="default"
                  onChangeText={address => setState({...state, address })}
                />
              </Item>
            </Form>

            <Button
              style={styles.button}
              full
              rounded
              onPress={() => {
                // save contact
                saveContact();
              }}
            >
              <Text style={styles.buttonText}>Save</Text>
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
  imagePicker: {
    justifyContent: "center",
    alignSelf: "center",
    width: 100,
    height: 100,
    borderRadius: 100,
    borderColor: "#c1c1c1",
    borderWidth: 2
  },
  inputItem: {
    margin: 10
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
