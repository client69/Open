import { combineReducers } from "redux";
import productReducer from "./product/productReducer";
import userReducer from "./user/userReducer";

const rootReducer = combineReducers({
  user: userReducer,
  products: productReducer,
});

export default rootReducer;
