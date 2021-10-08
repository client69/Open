import { USER_LOGGED_IN, USER_LOGGED_OUT } from "./userTypes";

export const setLoggedIn = (userId, companyName, email) => {
  return {
    type: USER_LOGGED_IN,
    userId,
    isAuthenticated: true,
    companyName,
    email,
  };
};

export const setLoggedOut = () => {
  return {
    type: USER_LOGGED_OUT,
  };
};
