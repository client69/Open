import { useTheme } from "@react-navigation/native";
import React, { useEffect, useRef } from "react";
import {
  Alert,
  Animated,
  FlatList,
  RefreshControl,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,
} from "react-native";
import { useSelector } from "react-redux";
import firebase from "firebase";
import { useDispatch } from "react-redux";
import {
  decrementStock,
  fetchProducts,
  incrementStock,
  searchItem,
  setNewProductStock,
  setNewSearchItems,
  sortProducts,
} from "../redux/product/productAction";
import {
  Body,
  Button,
  Card,
  CardItem,
  Header,
  Icon,
  Input,
  Item,
  Left,
  Right,
  Thumbnail,
  Title,
  Toast,
} from "native-base";
import SearchNotFound from "./Reusables/assets/SearchNotFound";
import {
  SORT_BY_PRODUCT_ID_ASC,
  SORT_BY_PRODUCT_ID_DEC,
  SORT_BY_PRODUCT_NAME_ASC,
  SORT_BY_PRODUCT_NAME_DEC,
  SORT_BY_PRODUCT_QUANTITY_ASC,
  SORT_BY_PRODUCT_QUANTITY_DEC,
} from "../redux/product/productTypes";

export default function Home({ navigation, toggleTheme, isEnabled }) {
  const { colors } = useTheme();
  const userId = useSelector((state) => state.user.userId);
  const { products, searchedItems } = useSelector((state) => state.products);
  const dispatch = useDispatch();
  const [refreshing, setRefreshing] = React.useState(false);
  const [isQuantityChanging, setIsQuantityChanging] = React.useState(null);
  const [newQuantityValue, setNewQuantityValue] = React.useState("1");
  const [currentFilterTask, setCurrentFilterTask] = React.useState(null);
  const [searchTerm, setSearchTerm] = React.useState("");
  const [currentlySortedBy, setCurrentlySortedBy] = React.useState(null);

  useEffect(() => {
    fetchProducts(dispatch, userId);
  }, []);

  const onRefresh = async () => {
    setRefreshing(true);

    setSearchTerm("");
    handleSearchTermChange("");
    setCurrentFilterTask(null);
    fetchProducts(dispatch, userId).then(() => {
      setRefreshing(false);
      Toast.show({
        text: "Reloaded",
        swipeDisabled: false,
        type: "success",
      });
    });
  };

  const updateStock = (idx, isInc, val) => {
    setRefreshing(true);
    let oldVal = parseInt(searchedItems[idx].quantity);
    let newVal = oldVal;
    val = parseInt(val);
    var productIdx;
    products.forEach((d, i) => {
      if (d.docName === searchedItems[idx].docName) {
        productIdx = i;
      }
    });
    let dbRef = firebase
      .firestore()
      .collection(userId)
      .doc(searchedItems[idx].docName);
    if (isInc) {
      newVal += val;
      dbRef
        .update({
          quantity: newVal,
        })
        .then(() => {
          dispatch(
            incrementStock(products, productIdx, searchedItems, idx, newVal)
          );
          Toast.show({
            text: "Stock Updated",
            swipeDisabled: false,
            type: "success",
            duration: 2000,
          });
        });
    } else {
      newVal -= val;
      if (newVal >= 0) {
        dbRef
          .update({
            quantity: newVal,
          })
          .then(() => {
            dispatch(
              decrementStock(products, productIdx, searchedItems, idx, newVal)
            );
            Toast.show({
              text: "Stock Updated",
              swipeDisabled: false,
              type: "success",
              duration: 2000,
            });
          });
      } else {
        Toast.show({
          text: "Stock cannot be less than 0",
          swipeDisabled: false,
          type: "danger",
          duration: 2000,
        });
      }
    }
    setIsQuantityChanging(false);
    setRefreshing(false);
  };

  const setNewStockValue = (idx) => {
    var productIdx;
    products.forEach((d, i) => {
      if (d.docName === searchedItems[idx].docName) {
        productIdx = i;
      }
    });
    let dbRef = firebase
      .firestore()
      .collection(userId)
      .doc(searchedItems[idx].docName);
    let val = parseInt(newQuantityValue);
    if (val >= 0) {
      dbRef
        .update({
          quantity: val,
        })
        .then(() => {
          dispatch(
            setNewProductStock(
              products,
              productIdx,
              searchedItems,
              idx,
              newQuantityValue
            )
          );
          setNewQuantityValue("1");
          setIsQuantityChanging(false);
          Toast.show({
            text: "Updated",
            swipeDisabled: false,
            type: "success",
            duration: 2000,
          });
        })
        .catch((err) => {
          Toast.show({
            text: "Some Error Occured",
            swipeDisabled: false,
            type: "danger",
            duration: 2000,
          });
        });
    } else {
      Toast.show({
        text: "Stock cannot be less than 0",
        swipeDisabled: false,
        type: "danger",
        duration: 2000,
      });
    }
  };

  const deleteProduct = (docName, fileName, ext) => {
    Alert.alert(
      "Caution!!",
      "Are you sure you want to permanently delete this product?",
      [
        {
          text: "Cancel",
          onPress: () => console.log("Cancel Pressed"),
          style: "cancel",
        },
        {
          text: "Delete",
          onPress: async () => {
            setRefreshing(true);
            await firebase
              .storage()
              .ref(`productImages`)
              .child(userId)
              .child(`${fileName}.${ext}`)
              .delete();
            await firebase.firestore().collection(userId).doc(docName).delete();
            fetchProducts(dispatch, userId).then(() => {
              setRefreshing(false);
              Toast.show({
                text: "Deleted",
                swipeDisabled: false,
                type: "success",
              });
            });
          },
        },
      ],
      { cancelable: false }
    );
  };

  const handleSearchTermChange = (term) => {
    setSearchTerm(term);
    let itemsFound = searchItem(term.toUpperCase(), products);
    console.log(itemsFound);
    dispatch(setNewSearchItems(itemsFound));
  };

  const handleSortTypeChange = (type) => {
    setCurrentlySortedBy(type);
    dispatch(sortProducts(searchedItems, type, products));
  };

  useEffect(() => {
    console.log(currentlySortedBy);
  }, [currentlySortedBy]);

  const ProductCard = ({ product, idx }) => (
    <Card
      style={{
        backgroundColor: colors.productCard,
        borderRadius: 20,
        borderWidth: 0,
      }}
    >
      <CardItem style={{ backgroundColor: "transparent" }}>
        <Left>
          <Thumbnail
            source={{
              uri: product.downloadUrl,
            }}
            large={true}
          />
          <Body>
            <Text style={{ color: colors.text, fontSize: 22 }}>
              {product.productName}
            </Text>
            <Text note style={{ color: colors.text }}>
              ID: {product.productId}
            </Text>
            <Text note style={{ color: colors.text }}>
              {product.description}
            </Text>
          </Body>
        </Left>
        <Right>
          <TouchableOpacity
            onPress={(e) => {
              deleteProduct(
                product.docName,
                product.fileName,
                product.fileExtension
              );
            }}
          >
            <Icon
              active
              name="delete"
              type="MaterialCommunityIcons"
              style={{ color: colors.text }}
            />
          </TouchableOpacity>
        </Right>
      </CardItem>
      {isQuantityChanging === product.docName ? (
        <CardItem style={{ backgroundColor: "transparent" }}>
          <Left>
            <Item rounded>
              <Input
                autoFocus={true}
                placeholder="Value"
                value={newQuantityValue}
                onChangeText={(val) => {
                  setNewQuantityValue(val);
                }}
                style={{ color: colors.text }}
              />
            </Item>
          </Left>
          <Body
            style={{
              display: "flex",
              flexDirection: "row",
              justifyContent: "space-between",
              alignItems: "center",
            }}
          >
            <TouchableOpacity
              onPress={(e) => {
                updateStock(idx, true, newQuantityValue);
                setNewQuantityValue("1");
              }}
            >
              <Icon
                active
                name="plus"
                type="FontAwesome"
                style={{ color: "#0dff00" }}
              />
            </TouchableOpacity>
            <TouchableOpacity
              onPress={(e) => {
                updateStock(idx, false, newQuantityValue);
                setNewQuantityValue("1");
              }}
            >
              <Icon
                active
                name="minus"
                type="FontAwesome"
                style={{ color: "#ff0008" }}
              />
            </TouchableOpacity>
            <TouchableOpacity
              onPress={(e) => {
                setNewStockValue(idx);
              }}
            >
              <Icon
                active
                name="save"
                type="Entypo"
                style={{ color: "#0dff00" }}
              />
            </TouchableOpacity>
            <TouchableOpacity
              onPress={(e) => {
                setIsQuantityChanging(null);
              }}
            >
              <Icon
                active
                name="cross"
                type="Entypo"
                style={{ color: "#ff0008" }}
              />
            </TouchableOpacity>
          </Body>
        </CardItem>
      ) : (
        <CardItem style={{ backgroundColor: "transparent" }}>
          <Left>
            <TouchableOpacity
              onPress={(e) => {
                updateStock(idx, true, 1);
              }}
            >
              <Icon
                active
                name="plus"
                type="FontAwesome"
                style={{ color: "#0dff00" }}
              />
            </TouchableOpacity>
          </Left>

          <Body>
            <Button
              transparent
              style={{
                display: "flex",
                justifyContent: "center",
                alignItems: "center",
              }}
            >
              <Text style={{ color: colors.text }}>
                Quantity: {product.quantity}
              </Text>
              <TouchableOpacity
                style={{ marginLeft: 3 }}
                onPress={(e) => {
                  setIsQuantityChanging(product.docName);
                }}
              >
                <Icon
                  active
                  name="edit-3"
                  type="Feather"
                  style={{ color: colors.text }}
                />
              </TouchableOpacity>
            </Button>
          </Body>
          <Right>
            <TouchableOpacity
              onPress={(e) => {
                updateStock(idx, false, 1);
              }}
            >
              <Icon
                active
                name="minus"
                type="FontAwesome"
                style={{ color: "#ff0008" }}
              />
            </TouchableOpacity>
          </Right>
        </CardItem>
      )}
    </Card>
  );

  // useEffect(() => {
  //   console.log(products);

  // }, [products]);
  return (
    <View style={styles.mainContainer}>
      {/* {products && products.map((val, idx) => <ProductCard idx={idx} />)} */}
      <Header style={{ ...styles.header, backgroundColor: colors.card }}>
        {currentFilterTask === "search" ? (
          <TouchableOpacity
            style={styles.filterButtons}
            onPress={(e) => {
              setCurrentFilterTask(null);
              dispatch(setNewSearchItems(products));
              setSearchTerm("");
            }}
          >
            <Icon type="Entypo" name="cross" style={{ color: "#fc0303" }} />
          </TouchableOpacity>
        ) : (
          <TouchableOpacity
            style={styles.filterButtons}
            onPress={(e) => {
              setCurrentFilterTask("search");
            }}
          >
            <Icon
              type="FontAwesome"
              name="search"
              style={{ color: colors.text }}
            />
          </TouchableOpacity>
        )}

        {currentFilterTask === "sort" ? (
          <TouchableOpacity
            style={styles.filterButtons}
            onPress={(e) => {
              setCurrentFilterTask(null);
            }}
          >
            <Icon type="Entypo" name="cross" style={{ color: "#fc0303" }} />
          </TouchableOpacity>
        ) : (
          <TouchableOpacity
            style={styles.filterButtons}
            onPress={(e) => {
              setCurrentFilterTask("sort");
            }}
          >
            <Icon
              type="MaterialIcons"
              name="sort"
              style={{ color: colors.text }}
            />
          </TouchableOpacity>
        )}
      </Header>
      <View style={styles.filterOptionContainer}>
        {currentFilterTask === "search" && (
          <View style={{ ...styles.searchContainer }}>
            <Text style={{ color: colors.text, fontSize: 30 }}>Search</Text>
            <Item>
              <Icon
                type="FontAwesome"
                name="search"
                style={{ color: colors.text }}
              />
              <Input
                placeholder="Search Term"
                keyboardType="default"
                onChangeText={(term) => {
                  handleSearchTermChange(term);
                }}
                value={searchTerm}
                style={{ color: colors.text }}
              />
            </Item>
          </View>
        )}

        {/* =================================Sort Buttons Goes Here================================= */}
        {currentFilterTask === "sort" ? (
          <View
            style={{
              ...styles.searchContainer,
              marginHorizontal: 4,
              marginVertical: 2,
              display: "flex",
              flexDirection: "row",
              justifyContent: "space-between",
              flexWrap: "wrap",
            }}
          >
            <Button
              iconLeft
              transparent
              style={{
                backgroundColor:
                  currentlySortedBy === SORT_BY_PRODUCT_NAME_DEC
                    ? colors.activeButton
                    : colors.text,
                borderColor: colors.notification,
                padding: 5,
                marginVertical: 4,
              }}
              bordered
              rounded
              onPress={(e) => {
                handleSortTypeChange(SORT_BY_PRODUCT_NAME_DEC);
              }}
            >
              <Icon
                name="sort-alpha-desc"
                type="FontAwesome"
                style={{ color: colors.background }}
              />
              <Text style={{ color: colors.background, marginHorizontal: 4 }}>
                Product Name
              </Text>
            </Button>
            <Button
              iconLeft
              transparent
              style={{
                backgroundColor:
                  currentlySortedBy === SORT_BY_PRODUCT_NAME_ASC
                    ? colors.activeButton
                    : colors.text,
                borderColor: colors.notification,
                padding: 5,
                marginVertical: 4,
              }}
              bordered
              rounded
              onPress={() => {
                handleSortTypeChange(SORT_BY_PRODUCT_NAME_ASC);
              }}
            >
              <Icon
                name="sort-alpha-asc"
                type="FontAwesome"
                style={{ color: colors.background }}
              />
              <Text style={{ color: colors.background, marginHorizontal: 4 }}>
                Product Name
              </Text>
            </Button>
            <Button
              iconLeft
              transparent
              style={{
                backgroundColor:
                  currentlySortedBy === SORT_BY_PRODUCT_ID_DEC
                    ? colors.activeButton
                    : colors.text,
                borderColor: colors.notification,
                padding: 5,
                marginVertical: 4,
              }}
              bordered
              rounded
              onPress={() => {
                handleSortTypeChange(SORT_BY_PRODUCT_ID_DEC);
              }}
            >
              <Icon
                name="sort-alpha-desc"
                type="FontAwesome"
                style={{ color: colors.background }}
              />
              <Text style={{ color: colors.background, marginHorizontal: 4 }}>
                Product ID
              </Text>
            </Button>
            <Button
              iconLeft
              transparent
              style={{
                backgroundColor:
                  currentlySortedBy === SORT_BY_PRODUCT_ID_ASC
                    ? colors.activeButton
                    : colors.text,
                borderColor: colors.notification,
                padding: 5,
                marginVertical: 4,
              }}
              bordered
              rounded
              onPress={() => {
                handleSortTypeChange(SORT_BY_PRODUCT_ID_ASC);
              }}
            >
              <Icon
                name="sort-alpha-asc"
                type="FontAwesome"
                style={{ color: colors.background }}
              />
              <Text style={{ color: colors.background, marginHorizontal: 4 }}>
                Product ID
              </Text>
            </Button>
            <Button
              iconLeft
              transparent
              style={{
                backgroundColor:
                  currentlySortedBy === SORT_BY_PRODUCT_QUANTITY_DEC
                    ? colors.activeButton
                    : colors.text,
                borderColor: colors.notification,
                padding: 5,
                marginVertical: 4,
              }}
              bordered
              rounded
              onPress={() => {
                handleSortTypeChange(SORT_BY_PRODUCT_QUANTITY_DEC);
              }}
            >
              <Icon
                name="sort-numeric-desc"
                type="FontAwesome"
                style={{ color: colors.background }}
              />
              <Text style={{ color: colors.background, marginHorizontal: 4 }}>
                Product Quantity
              </Text>
            </Button>
            <Button
              iconLeft
              transparent
              style={{
                backgroundColor:
                  currentlySortedBy === SORT_BY_PRODUCT_QUANTITY_ASC
                    ? colors.activeButton
                    : colors.text,
                borderColor: colors.notification,
                padding: 5,
                marginVertical: 4,
              }}
              bordered
              rounded
              onPress={() => {
                handleSortTypeChange(SORT_BY_PRODUCT_QUANTITY_ASC);
              }}
            >
              <Icon
                name="sort-numeric-asc"
                type="FontAwesome"
                style={{ color: colors.background }}
              />
              <Text style={{ color: colors.background, marginHorizontal: 4 }}>
                Product Quantity
              </Text>
            </Button>
          </View>
        ) : null}
      </View>
      <FlatList
        data={searchedItems}
        renderItem={(product) => (
          <ProductCard product={product.item} idx={product.index} />
        )}
        keyExtractor={(product) => {
          return product.docName;
        }}
        refreshControl={
          <RefreshControl refreshing={refreshing} onRefresh={onRefresh} />
        }
        keyboardShouldPersistTaps="always"
        ListEmptyComponent={<SearchNotFound />}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  mainContainer: {
    marginTop: 0,
    flex: 1,
  },
  header: {
    display: "flex",
    justifyContent: "flex-end",
    alignItems: "center",
  },
  filterButtons: {
    marginHorizontal: 10,
  },
  filterOptionContainer: {
    width: "100%",
    backgroundColor: "transparent",
    marginVertical: 3,
  },
  searchContainer: {},
});
