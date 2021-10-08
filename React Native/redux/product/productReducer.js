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

const initialState = {
  products: [],
  loading: false,
  error: "",
  searchedItems: [],
};

const productReducer = (state = initialState, action) => {
  switch (action.type) {
    case FETCH_PRODUCTS_REQUEST:
      return {
        ...state,
        loading: true,
      };
    case FETCH_PRODUCT_SUCCESS:
      return {
        ...state,
        loading: false,
        products: action.payload,
        searchedItems: action.payload,
        error: "",
      };
    case FETCH_PRODUCT_FAILURE:
      return {
        ...state,
        loading: false,
        products: [],
        searchedItems: [],
        error: action.payload,
      };
    case INCREMENT_PRODUCT_STOCK:
      return {
        ...state,
        products: action.payload,
        searchedItems: action.searchedItems,
      };
    case DECREMENT_PRODUCT_STOCK:
      return {
        ...state,
        products: action.payload,
        searchedItems: action.searchedItems,
      };
    case NEW_PRODUCT_STOCK:
      return {
        ...state,
        products: action.payload,
        searchedItems: action.searchedItems,
      };
    case SET_SEARCH_ITEMS:
      return {
        ...state,
        searchedItems: action.payload,
      };
    default:
      return state;
  }
};
export default productReducer;
