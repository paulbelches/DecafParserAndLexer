#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Descriptor {
  public:
  //Registry descriptor
  map<string, vector<string>> registry;
  queue<string> availableRegistrys;
  
  //Address descriptor
  map<string, vector<string>> address;
  vector<string> registerVariables;

  //Registry descriptorr
  string getFreeRegistry() {
    string r = availableRegistrys.front();
    availableRegistrys.pop();
    return r;
  }

  void freeRegistry(string id) {
    vector<string> tempValue;
    registry[id] = tempValue;
    availableRegistrys.push(id);
  }

  void setRegistry(string id, string value) {
    vector<string> tempValue;
    tempValue.push_back(value);
    registry[id] = tempValue;
  }

  void addToRegistry(string id, string value) {
    registry[id].push_back(value);
  }


  //Address descriptor
  void setAddress(string id, string value) {
    vector<string> tempValue;
    tempValue.push_back(value);
    address[id] = tempValue;
  }

  void addToAddress(string id, string value) {
    address[id].push_back(value);
  }

  void eliminateRegistry(string value){
    map<string, vector<string>>::iterator it = address.begin();
    while (it != address.end()){
      vector<string> tempVector = it->second;
      vector<string>::iterator it2 = find(tempVector.begin(), tempVector.end(), value);
      if (it2 != tempVector.end())
        tempVector.erase(it2);
      it++;
    }
  }

  bool isRegister(string id){
    vector<string>::iterator it = find(registerVariables.begin(), registerVariables.end(), id);
    return it != registerVariables.end();
  }

  bool hasRegistry(string id){
    vector<string> values = address[id];
    for (int i = 0; i < values.size(); i++){
      if (values[i] != id){
        return true;
      }
    }
    return false;
  }

  string getRegistry(string id){
    vector<string> values = address[id];
    for (int i = 0; i < values.size(); i++){
      if (values[i] != id){
        return values[i];
      }
    }
    return "";
  }

////////////////////////////////////////////////////////////////////

  //Get the location where the variable is store or a new one
  string getReg(string id){
    //Check if it is register
    if (id == "$zero"){
      return "$zero";
    } else if (!hasRegistry(id)){
      string resultReg;
      // Check if it needs to be load
      if (id[0] == 'l'){
        resultReg = getResultReg(id, "LD", "");
        std::size_t start = id.find("[") + 1;
        std::size_t end = id.find("]");
        string temporal = id.substr(start, end - start);
        string temporalRegistry = getRegistry(temporal);
        //get temporal registry
        cout << "add $sp $fp " << temporalRegistry << endl;
        cout << "lw "<< resultReg << " ($sp)" << endl;
      } else {
        resultReg = getResultReg(id, "LD", "");
        cout << "#LW "+resultReg+" "+id << endl;
      }
      return resultReg;
    } else {
      return getRegistry(id);
    }
  }

  string getResultReg(string id, string op, string rID){
    string registerId;
    if (!hasRegistry(id)){
      registerId = availableRegistrys.front();
      availableRegistrys.pop(); 
    } else {
      registerId = getRegistry(id);
    }
    if (op == "LD"){
      setRegistry(registerId, id);
      addToAddress(id, registerId);
    } else if (op == "ST"){
      addToAddress(id, id);
    } else if (op == "ADD"){
      setRegistry(registerId, id);
      eliminateRegistry(registerId);
      setAddress(id, registerId);
    } else if (op == "EQ"){
      addToRegistry(rID, id);
      setAddress(id, rID);
    }
    return registerId;
  }

  void clear(){
    registry.clear();
    queue<string> tempAvailableRegistrys;
    availableRegistrys = tempAvailableRegistrys;
    address.clear();
    registerVariables.clear();
    for (int i = 0; i < 8; i++){
      freeRegistry("$t" + to_string(i));
    }
  }
};