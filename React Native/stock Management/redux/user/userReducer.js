import { USER_LOGGED_IN, USER_LOGGED_OUT } from "./userTypes";

const initialState = {
  userId: null,
  isAuthenticated: false,
  companyName: "",
  email: "",
};

const userReducer = (state = initialState, action) => {
  switch (action.type) {
    case USER_LOGGED_IN:
      return {
        ...state,
        userId: action.userId,
        isAuthenticated: action.isAuthenticated,
        companyName: action.companyName,
        email: action.email,
      };
    case USER_LOGGED_OUT:
      return {
        ...state,
        userId: null,
        isAuthenticated: false,
        companyName: "",
        email: "",
      };
    default:
      return state;
  }
};

export default userReducer;
