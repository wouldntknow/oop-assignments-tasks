#include <iostream>
#include <string>
#include <list>
using namespace std;
class securityTool {
private:
    string securityLevel;
    float cost;
    int numOfDevices;

public:
    securityTool(string l, float c, int n) : securityLevel(l), cost(c), numOfDevices(n) {}

    void setLevel(string level) {
        if (level == "High" || level == "Low" || level == "Medium") {
            securityLevel = level;
        } else {
            cout << "Invalid input, try again!" << endl;
            setLevel(level);
        }
    }

    void setCost(float c) {
        if (c > 0) {
            cost = c;
        } else {
            cout << "Invalid input, try again!" << endl;
            setCost(c);
        }
    }

    void performScan() {
        cout << "Performing a generic scan..." << endl;
    }
    friend class firewallTool;
};

class firewallTool : public securityTool {
private:
    list<int> ports;
    list<string> protocols;

public:
    firewallTool(string level, float c, int devices, list<int> allowedPorts, list<string> allowedProtocols)
        : securityTool(level, c, devices), ports(allowedPorts), protocols(allowedProtocols) {}

    list<int> generateList(int startPort) {
        list<int> allowedPorts;
        for (int i = startPort; i < startPort + 23; ++i) {
            allowedPorts.push_back(i);
        }
        return allowedPorts;
    }

    void performScan() {
        if (securityLevel == "High") {
            cout << "Performing a high security scan..." << endl;
            cout << "Only allowing traffic from specified ports and protocols." << endl;
        } else if (securityLevel == "Medium") {
            cout << "Performing a medium security scan..." << endl;
            cout << "Allowing traffic from specified ports and protocols, and the next two ports in sequence." << endl;
        } else if (securityLevel == "Low") {
            cout << "Performing a low security scan..." << endl;
            cout << "Allowing traffic from specified ports and protocols, and the next five ports in sequence." << endl;
            cout << "Additionally, allowing traffic from TCP and DNS protocols." << endl;
        } else {
            cerr << "Invalid security level." << endl;
        }
    }
};

int main() {
    int number = 2; // Starting port number

    firewallTool firewall("High", 100.0, 10, {}, {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"});
    firewall.performScan();

    return 0;
}
