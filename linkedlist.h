typedef struct ChainNode {
    friend class Chain;
    private:
        //std::string data;
        int data;
        ChainNode* link;
} node;

class Chain {
    private:
        node* first = NULL;
        node* last = NULL;

    public:
        node* createNode(std::string strValue);
        node* getNode(std::string strValue);
        void insert(std::string targetValue, std::string value, bool status);
        void insertListFront(std::string value, bool status); 
        void insertListBack(std::string value, bool status); 
        void deleteNode(std::string deleteValue); 
        void reverse();
        void printList();
};
