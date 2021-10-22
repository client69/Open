import java.io.IOException;
import java.io.Serializable;
import java.util.Map;

public abstract class User implements Serializable {
    protected String username;
   protected String email;
    protected String passwd;
    protected String phone;
    protected Map<String,Integer> movieSeen;
    protected boolean loginStatus=false;

   public abstract boolean usname(String a);

    public abstract boolean emal(String a) throws IOException, ClassNotFoundException;

    public abstract boolean pass(String a);

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPasswd() {
        return passwd;
    }

    public void setPasswd(String passwd) {
        this.passwd = passwd;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public Map<String, Integer> getMovieSeen() {
        return movieSeen;
    }

    public void setMovieSeen(Map<String, Integer> movieSeen) {
        this.movieSeen = movieSeen;
    }

    public boolean isLoginStatus() {
        return loginStatus;
    }

    public void setLoginStatus(boolean loginStatus) {
        this.loginStatus = loginStatus;
    }

    public abstract boolean pho(String a);

    public abstract boolean Confirmpass(String a);
}
