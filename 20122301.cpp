#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

int main() {
    Chain Chain;
    string strInput;
    string input[100000];

    string val;

    for(int index = 0; index < 100000; index++) {
        getline(std::cin, input[index]);
        if(input[index].find("I ") == 0) {
            string target;
            int startPoint = 2;
            for(int i = 2; i < input[index].length(); i++) {
                if((input[index].at(i) == ' ') || i == input[index].length()-1) {
                    if(i == input[index].length()-1) {
                        val = input[index].substr(startPoint, i-startPoint+1);
                    } else {
                        target = input[index].substr(startPoint, i-startPoint);
                    }
                    startPoint = i+1; 
                }
            }
            Chain.insert(target, val, true);

        } else if(input[index].find("IB") == 0) {
            int startPoint = 3;
            for(int i = 3; i < input[index].length(); i++) {
                if((input[index].at(i) == ' ') || i == input[index].length()-1) {
                    if(i == input[index].length()-1) {
                        val = input[index].substr(startPoint, i-startPoint+1);
                    } else {
                        val = input[index].substr(startPoint, i-startPoint);
                    }
                    if(i == input[index].length()-1) {
                        Chain.insertListBack(val, true);
                    } else {
                        Chain.insertListBack(val, false);
                    }
                    startPoint = i+1; 
                }
            }

        } else if(input[index].find("IF") == 0) {
            int startPoint = 3;
            int cnt = 0;
            string firstValue;

            for(int i = 3; i < input[index].length(); i++) {
                if((input[index].at(i) == ' ') || i == input[index].length()-1) {
                    cnt++;
                    if(i == input[index].length()-1) {
                        val = input[index].substr(startPoint, i-startPoint+1);
                    } else {
                        val = input[index].substr(startPoint, i-startPoint);
                    }
                    if(cnt == 1) {
                        Chain.insertListFront(val, true);
                        firstValue = val;
                    } else {
                        Chain.insert(firstValue, val, false); 
                        firstValue = val;
                    }
                    startPoint = i+1; 
                }
            }

        } else if(input[index].find("D") == 0) {
            val = input[index].substr(2, input[index].length()-1);
            Chain.deleteNode(val);

        } else if(input[index].find("P") == 0) {
            Chain.printList();

        } else if(input[index].find("R") == 0) {
            Chain.reverse();

        }
    }
    
    return 0;
}
