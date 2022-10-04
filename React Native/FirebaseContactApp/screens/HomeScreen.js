import React, { useState, useEffect } from "react";
// import needed Components
import {
  StyleSheet,
  TouchableOpacity,
  Text,
  View,
  FlatList,
  Image,
  ActivityIndicator
} from "react-native";
// install native-base and import card from it
import { Card } from "native-base";
//import Entypo icons from @expo
import { Entypo } from "@expo/vector-icons";

//TODO: add firebase
import * as firebase from 'firebase'

export default function HomeScreen({route,navigation}){  
  //TODO: add constructor with state: data[], isLoading, isListEmpty
  

  const [state,setState] = useState({
    data:[],
    isLoading: true,
    isListEmpty:false
  })
  const [data,setData] = useState([])
  const [isListEmpty,setIsListEmpty] = useState(false)
  const [reload,setReload] = useState(false)
  
  // lifecycle method
  
  useEffect(() => {
    getAllContact()
  }, [])
  // getAllContact method
  const getAllContact = async () => {    
    //TODO: get all contact from firebase
    let contactRef = firebase.database().ref()
    await contactRef.on("value", dataSnapshot => {      
      if(dataSnapshot.val()){                
        let contactResult = Object.values(dataSnapshot.val())
        let contactKey = Object.keys(dataSnapshot.val())
        contactKey.forEach((value,key) => {
          contactResult[key]["key"] = value;          
        })        
        setData(         
          contactResult.sort((a,b) => {
            var nameA = a.fname.toUpperCase()
            var nameB = b.fname.toUpperCase()            
            if(nameA < nameB){
              return -1
            }
            if(nameA > nameB){
              return 1
            }
            return 0
          }),                 
        )                
      }else{
        setIsListEmpty(true)              
      }
      setState({...state, isLoading:false})
    })
    //TODO:
    // sort array by fname and set it to data state  
  };

  const LoadingScreen = () => {
    if(state.isLoading){
    return (
      <View
        style={{ flex: 1, alignContent: "center", justifyContent: "center" }}
      >
        <ActivityIndicator size="large" color="#B83227" />
        <Text style={{ textAlign: "center" }}>
          Contacts loading please wait..
        </Text>
      </View>
    );
    }
  }
  const NoItemfound = () => {
    if(isListEmpty){
    return (
      <View
        style={{ flex: 1, alignContent: "center", justifyContent: "center" }}
      >
        <Text style={{ textAlign: "center" }}>No Contacts please Add</Text>
        
        <Entypo style={{ alignSelf: "center" }} name="plus" size={35} />          
        <TouchableOpacity
          onPress={() => {
            // add icon
            //navigate to Add Contact screen
            navigation.navigate("Add");
          }}
          style={styles.floatButton}
        >
          <Entypo name="plus" size={30} color="#fff" />
        </TouchableOpacity>
      </View>
    );
        }
  }

  const MainScreen = () => {
    if(state.isLoading){
      return (<LoadingScreen />)
    }
    if(isListEmpty){
      return (<NoItemfound />)
    }
    
    return (
      <View style={styles.container}>        
        <FlatList
          data={data}
          renderItem={({ item }) => {
            return (
              <TouchableOpacity
                onPress={() => {
                  //navigate to view contact screen with passing key
                  navigation.navigate("View", {
                    key: item.key,
                    getAllContact
                  });
                }}
              >
                <Card style={styles.listItem}>
                  <View>
                    <Image
                      style={styles.contactIcon}
                      source={
                        item.imageUrl === "empty"
                          ? require("../assets/person.png")
                          : { uri: item.imageUrl }
                      }
                    />
                  </View>
                  <View style={styles.infoContainer}>
                    <Text style={styles.infoText}>
                      {item.fname} {item.lname}
                    </Text>
                    <Text style={styles.infoText}>{item.phone}</Text>
                  </View>
                </Card>
              </TouchableOpacity>
            );
          }}
        />

        <TouchableOpacity
          onPress={() => {
            // add icon
            //navigate to Add Contact screen
            navigation.navigate("Add",{getAllContact});
          }}
          style={styles.floatButton}
        >
          <Entypo name="plus" size={30} color="#fff" />
        </TouchableOpacity>
      </View>
    );         

  }

  // render method  
    // if its loading show ActivityIndicator
    // if (state.isLoading) {
      
    // }  if (state.isListEmpty) {
    //   // else if loading is completed and no contact found show this
      
    // }
    // return list of contacts     
    return(
      <MainScreen />
    )
}
// styles
const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff"
  },
  listItem: {
    flexDirection: "row",
    padding: 20
  },
  contactIcon: {
    width: 60,
    height: 60,
    borderRadius: 100
  },
  infoContainer: {
    flexDirection: "column"
  },
  infoText: {
    fontSize: 16,
    fontWeight: "400",
    paddingLeft: 10,
    paddingTop: 2
  },
  floatButton: {
    borderWidth: 1,
    borderColor: "rgba(0,0,0,0.2)",
    alignItems: "center",
    justifyContent: "center",
    width: 60,
    position: "absolute",
    bottom: 10,
    right: 10,
    height: 60,
    backgroundColor: "#B83227",
    borderRadius: 100
  }
});
