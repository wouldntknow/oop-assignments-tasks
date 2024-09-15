#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Post;

class User {
public:
    string username;
    string password;
    string email;
    int number;

    User(const string& u, const string& p, const string& e, int n)
        : username(u), password(p), email(e), number(n) {}

    virtual ~User() {}

    void signUp() {
        cout << "Signing you up....." << endl;
    }

    void savedInfo() {
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Email: " << email << endl;
        cout << "Phone number: " << number << endl;
    }

    void LoginVerification() {
        string tempUser, tempPass;
        cout << "Login by entering correct username and Password." << endl;
        cout << "Username: ";
        cin >> tempUser;
        cout << "Password: ";
        cin >> tempPass;
        if (tempUser == username && tempPass == password) {
            cout << "Logging you in....." << endl;
        }
    }
};

class RegularUser : public User {
private:
    int count = 0;
    string caption;
    static const int MAX_POSTS = 5;
    vector<Post*> feed;

public:
    RegularUser(const string& u, const string& p, const string& e, int n)
        : User(u, p, e, n) {}

    void Posting() {
        cout << "Write down your posting caption here: ";
        getline(cin, caption);  // Use getline to read the entire line
        cout << "Your post has been uploaded successfully!" << endl;
        count++;
        if (count >= MAX_POSTS) {
            cout << "You have reached your posting limits for the day! Come back later..." << endl;
        }
    }

    void addToFeed(Post* post) {
        if (feed.size() < MAX_POSTS) {
            feed.push_back(post);
        } else {
            cout << "Limit reached for RegularUser " << username << endl;
        }
    }

    void viewFeed() {
        for (auto& post : feed) {
            post->display();
        }
    }

    
   
};

class BusinessUser : public User {
private:
    string posts;
    string choice;
    static const int PROMOTION_LIMIT = 10;
    int promotedPostsCount;
    vector<Post*> promotedPosts;

public:
    BusinessUser(const string& u, const string& p, const string& e, int n)
        : User(u, p, e, n), promotedPostsCount(0) {}

    void Posting() {
        cout << "Write down your posting caption here: ";
        getline(cin, posts);  // Use getline to read the entire line
        cout << "Your post has been uploaded successfully!" << endl;
    }

    void promotePost(Post* post) {
        cout << "Do you want to promote your post? (Y/N): ";
        cin >> choice;
        if (choice == "Y" || choice == "y") {
            if (promotedPostsCount < PROMOTION_LIMIT) {
                post->increaseLikes(2);
                post->increaseViews(3);
                promotedPosts.push_back(post);
                promotedPostsCount++;
            } else {
                cout << "Promotion limit reached for BusinessUser " << username << endl;
            }
        } else {
            cout << "Your post will not be promoted." << endl;
        }
    }

  
};

class Post {
private:
    static int nextId;
    int postId;
    string content;
    int likes;
    int comments;
    int views;

public:
    Post(const string& content) : postId(nextId++), content(content), likes(0), comments(0), views(0) {}

    void addComment() {
        comments++;
    }

    void like() {
        likes++;
    }

    void display() {
        cout << "Post ID: " << postId << endl;
        cout << "Content: " << content << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
        cout << "Views: " << views << endl;
    }

    void increaseLikes(int amount) {
        likes += amount;
    }

    void increaseViews(int amount) {
        views += amount;
    }

    int getLikes() const {
        return likes;
    }

    int getComments() const {
        return comments;
    }

    int getViews() const {
        return views;
    }
};


int Post::nextId = 1;

int main() {
  
    RegularUser regUser("JohnDoe", "password123", "john@example.com", 123456789);
    BusinessUser busUser("JaneDoe", "password456", "jane@example.com", 987654321);

    regUser.signUp();
    regUser.savedInfo();
    regUser.LoginVerification();

    busUser.signUp();
    busUser.savedInfo();
    busUser.LoginVerification();

    return 0;
}
