import { useState } from "react";
import db from "../nedb/items";
import "../App.css";

export const CreateItem = ({ items, setItems }) => {
  const [item, setItem] = useState("");
  const saveItemToDB = (e) => {
    e.preventDefault();

    let doc = {
      item,
      dateAdded: String(
        new Date().getDate() +
          "/" +
          (new Date().getMonth() + 1) +
          "/" +
          new Date().getFullYear()
      ),
    };
    db.insert(doc, (err, newDoc) => {
      if (!err) {
        console.info("Item Added");
        setItems([...items, doc]);
        setItem("");
      }
    });
  };
  return (
    <div className="formContainer">
      <input
        type="text"
        placeholder="Enter Item"
        className="inputTODO"
        onChange={(e) => {
          setItem(e.target.value);
        }}
        value={item}
      />
      <button className="addItem" onClick={saveItemToDB}>
        Add Item
      </button>
    </div>
  );
};
