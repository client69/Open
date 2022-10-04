import db from "../nedb/items";
import "../App.css";

export const Item = ({ item, idx, items, setItems }) => {
  const deleteItem = (e) => {
    e.preventDefault();
    db.remove({ _id: item._id }, {}, (err, numRemoved) => {
      if (!err) {
        console.log("DELETED: ", item._id);
        setItems([...items.slice(0, idx), ...items.slice(idx + 1)]);
      }
    });
  };
  return (
    <div className="item">
      <div className="title">{item.item}</div>
      <div className="date">
        {item.dateAdded}
        <button className="delete" onClick={deleteItem}>
          delete
        </button>
      </div>
    </div>
  );
};
