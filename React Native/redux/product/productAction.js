import {
  DECREMENT_PRODUCT_STOCK,
  FETCH_PRODUCTS_REQUEST,
  FETCH_PRODUCT_FAILURE,
  FETCH_PRODUCT_SUCCESS,
  INCREMENT_PRODUCT_STOCK,
  NEW_PRODUCT_STOCK,
  SET_SEARCH_ITEMS,
  SORT_BY_PRODUCT_ID_ASC,
  SORT_BY_PRODUCT_ID_DEC,
  SORT_BY_PRODUCT_NAME_ASC,
  SORT_BY_PRODUCT_NAME_DEC,
  SORT_BY_PRODUCT_QUANTITY_ASC,
  SORT_BY_PRODUCT_QUANTITY_DEC,
} from "./productTypes";
import firebase from "firebase";
import "firebase/firestore";
export const fetchProductsRequest = () => {
  return {
    type: FETCH_PRODUCTS_REQUEST,
  };
};

export const fetchProductsSuccess = (products) => {
  return {
    type: FETCH_PRODUCT_SUCCESS,
    payload: products,
  };
};

export const fetchProductFailure = (error) => {
  return {
    type: FETCH_PRODUCT_FAILURE,
    payload: error,
  };
};

export const incrementStock = (
  products,
  productIdx,
  searchedItems,
  searchedItemIdx,
  newVal
) => {
  products[productIdx].quantity = parseInt(newVal);
  searchedItems[searchedItemIdx].quantity = parseInt(newVal);
  return {
    type: INCREMENT_PRODUCT_STOCK,
    payload: products,
    searchedItems: searchedItems,
  };
};

export const decrementStock = (
  products,
  productIdx,
  searchedItems,
  searchedItemIdx,
  newVal
) => {
  products[productIdx].quantity = parseInt(newVal);
  searchedItems[searchedItemIdx].quantity = parseInt(newVal);
  return {
    type: DECREMENT_PRODUCT_STOCK,
    payload: products,
    searchedItems: searchedItems,
  };
};

export const setNewProductStock = (
  products,
  productIdx,
  searchedItems,
  searchedItemIdx,
  newVal
) => {
  products[productIdx].quantity = parseInt(newVal);
  searchedItems[searchedItemIdx].quantity = parseInt(newVal);
  return {
    type: NEW_PRODUCT_STOCK,
    payload: products,
    searchedItems: searchedItems,
  };
};

export const setNewSearchItems = (items) => {
  return {
    type: SET_SEARCH_ITEMS,
    payload: items,
  };
};

const sortArray = (arr, type, prop) => {
  if (type === "ASC") {
    arr.sort((a, b) => {
      if (a[prop] > b[prop]) {
        return 1;
      }
      if (a[prop] < b[prop]) {
        return -1;
      }
      return 0;
    });
  } else {
    arr.sort((a, b) => {
      if (a[prop] < b[prop]) {
        return 1;
      }
      if (a[prop] > b[prop]) {
        return -1;
      }
      return 0;
    });
  }
  return arr;
};

export const sortProducts = (allItems, type, dafaultProducts) => {
  let arr = [];
  switch (type) {
    case SORT_BY_PRODUCT_NAME_ASC:
      arr = sortArray(allItems, "ASC", "productName");
      return {
        type: SET_SEARCH_ITEMS,
        payload: arr,
      };
    case SORT_BY_PRODUCT_NAME_DEC:
      arr = sortArray(allItems, "DEC", "productName");
      return {
        type: SET_SEARCH_ITEMS,
        payload: arr,
      };
    case SORT_BY_PRODUCT_ID_ASC:
      arr = sortArray(allItems, "ASC", "productId");
      return {
        type: SET_SEARCH_ITEMS,
        payload: arr,
      };
    case SORT_BY_PRODUCT_ID_DEC:
      arr = sortArray(allItems, "DEC", "productId");
      return {
        type: SET_SEARCH_ITEMS,
        payload: arr,
      };
    case SORT_BY_PRODUCT_QUANTITY_ASC:
      arr = sortArray(allItems, "ASC", "quantity");
      return {
        type: SET_SEARCH_ITEMS,
        payload: arr,
      };
    case SORT_BY_PRODUCT_QUANTITY_DEC:
      arr = sortArray(allItems, "DEC", "quantity");
      return {
        type: SET_SEARCH_ITEMS,
        payload: arr,
      };
    case "RESET":
      return {
        type: SET_SEARCH_ITEMS,
        payload: dafaultProducts,
      };
  }
};

export const searchItem = (item, allItems) => {
  let foundItems = allItems.filter((d) => {
    if (
      d.productName.toUpperCase().indexOf(item) > -1 ||
      d.productId.toUpperCase().indexOf(item) > -1
    ) {
      return true;
    }
    return false;
  });
  return foundItems;
};

export const fetchProducts = async (dispatch, userId) => {
  dispatch(fetchProductsRequest());
  const dbRef = firebase
    .firestore()
    .collection(userId)
    .orderBy("createdAt", "asc");
  const snapshot = await dbRef.get();
  let products = [];
  snapshot.forEach((data) => {
    products.push(data.data());
  });
  if (snapshot.empty) {
    dispatch(fetchProductFailure("No Products found"));
  } else {
    dispatch(fetchProductsSuccess(products));
  }
};
