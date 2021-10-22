import Datastore from "nedb";
import path from "path";
const remote = window.require("electron").remote;

export default new Datastore({
  autoload: true,
  filename: path.join(remote.app.getPath("userData"), "/items.db"),
});
