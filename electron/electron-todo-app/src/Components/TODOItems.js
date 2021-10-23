import "../App.css";
import { Item } from "./Item";

export const TODOItems = ({ items, setItems }) => {
  return (
    <div className="items-cont">
      {items.map((val, idx) => (
        <Item
          key={val._id}
          item={val}
          idx={idx}
          items={items}
          setItems={setItems}
        />
      ))}
    </div>
  );
};
