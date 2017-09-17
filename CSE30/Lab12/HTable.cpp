#include <iostream>
#include <string>
#include "HTable.h"
using namespace std;

HTable::HTable(){
  max_size = 23;
  numel = 0;
  dt = new data [max_size];
  for (int i = 0; i < max_size; i++){
    dt[i].key = -1;
    dt[i].value = "N/A";
  }
}

HTable::HTable(int t_size){
  max_size = t_size;
  numel = 0;
  dt = new data [t_size];
  for (int i = 0; i < max_size; i++){
    dt[i].key = -1;
    dt[i].value = "N/A";
  }
}

int HTable::hash(int &k){
  //hash code = k%max_size
  return k % max_size;
}

int HTable::rehash(int &k){
  //rehash: (k+1)%max_size
  return (k + 1) % max_size;
}

int HTable::add(data &d){
  //if the table is full
  if (numel == max_size){
    return -1;
  }else{ //normal case
    int input_key = d.key;
    string input_value = d.value;

    //hash code
    int hash_code = hash(input_key);

    //if there is no collision
    if (dt[hash_code].key == -1){
	dt[hash_code].key = input_key;
	dt[hash_code].value = input_value;
	numel++;
	return 0;
      }else{ // if there is collision
	//call rehash function for new hash_code
	int rehash_code = rehash(input_key);
	
	while (rehash_code < max_size){
	  //if rehash code is avilable
	  if (dt[rehash_code].key == -1){
	    dt[rehash_code].key = input_key;
	    dt[rehash_code].value = input_value;
	    numel++;
	    return 0;
	  }
	  //search available spot if current rehash code is not available
	  rehash_code++;
	}
	//find available spot if all spots after rehash code are not available
	for (int i = 0; i < max_size; i++){
	  if (dt[i].key = -1){
	    dt[i].key = input_key;
	    dt[i].value = input_value;
	    numel++;
	    return 0;
	  }
	}
	//if there is no available spot at all
	return -1;
    }
  }
}

int HTable::remove(data &d){
  //if the table is empty
  if (numel == 0){
    return -1;
  }else{
    for (int i = 0; i < max_size; i++){
      //using key to remove
      if (dt[i].key == d.key){
	dt[i].key = -1;
	dt[i].value = "N/A";
	numel--;
	return 0;
      }
    }
    //the table does not have such key
    return -1;
  }
}

void HTable::output(){
  cout << "Table of Contents:" << endl;
  for (int i = 0; i < max_size; i++){
    cout << i << " -> " << dt[i].key << " " << dt[i].value << endl;
  }
  cout << "There are " << numel << " data element in the table" << endl;
}
