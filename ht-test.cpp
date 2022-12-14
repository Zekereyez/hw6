#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
#include <set>
using namespace std;





struct IntHash2 {
    // size_t size;
    IntHash2() {}
    HASH_INDEX_T operator()(const int& k) const
    {
        return k;
    }
};






int main()
{
    DoubleHashProber<std::string, MyStringHash > dh;
    // HashTable<
    //     std::string, 
    //     int, 
    //     DoubleHashProber<std::string, MyStringHash >, 
    //     std::hash<std::string>, 
    //     std::equal_to<std::string> > ht(0.7, dh);

    // This is just arbitrary code. Change it to test whatever you like about your 
    // hash table implementation.
    // for(size_t i = 0; i < 10; i++){
    //     std::stringstream ss;
    //     ss << "hi" << i;
    //     ht.insert({ss.str(), i});
    // }
    // if( ht.find("hi1") != nullptr ){
    //     cout << "Found hi1" << endl;
    //     ht["hi1"] += 1;
    //     cout << "Incremented hi1's value to: " << ht["hi1"] << endl;
    // }
    // if( ht.find("doesnotexist") == nullptr ){
    //     cout << "Did not find: doesnotexist" << endl;
    // }
    // cout << "HT size: " << ht.size() << endl;
    // ht.remove("hi7");
    // ht.remove("hi9");
    // cout << "HT size: " << ht.size() << endl;
    // if( ht.find("hi9") != nullptr ){
    //     cout << "Found hi9" << endl;
    // }
    // else {
    //     cout << "Did not find hi9" << endl;
    // }
    // ht.insert({"hi7",17});
    // cout << "size: " << ht.size() << endl;
    // return 0;


    // test 8 insert resize
    HashTable<string, int, DoubleHashProber<string, std::hash<string>>, hash<string>, equal_to<string> > ht;
    set<pair<string, int>> items;
    for(int i = 0; i < 5; i++) {
        pair<string, int> newItem(to_string(i), i);
        ht.insert(newItem);
        items.insert(newItem);
    }
    // EXPECT_EQ(ht.table_.size(), 11);
    // cout << ht.size() << endl;
    //add another item should resize
    cout <<"Finished for loop now ADDING THE BREAKER" << endl;
    pair<string,int> newItem(to_string(5),5);
    ht.insert(newItem);
    items.insert(newItem);
    // EXPECT_EQ(ht.table_.size(), 23);
    cout << "Back into MAIN" << endl;
    cout << ht.size() << endl;
    //check that all the items are still there
    // EXPECT_TRUE(verifyItems(ht, items));


    // HashTable<int, int, DoubleHashProber<int, std::hash<int>>, IntHash2, equal_to<int> > ht(0.9, DoubleHashProber<int, std::hash<int>>(), IntHash2());
    // set<pair<int, int>> items;
    // pair<int,int> pair1(1,1);
    // pair<int,int> pair2(3,1);
    // pair<int,int> pair3(12,11);
    // pair<int,int> pair4(89,23);
    // pair<int,int> pair5(2,2);
    // pair<int,int> pair6(46,46);
    // items.insert(pair1);
    // items.insert(pair2);
    // items.insert(pair3);
    // items.insert(pair4);
    // items.insert(pair5);
    // items.insert(pair6);
    // //first item = loc = 1
    // ht.insert(pair1);
    // // EXPECT_EQ(ht.probe(pair1.first),1);
    // //second item = loc = 3
    // ht.insert(pair2);
    // // EXPECT_EQ(ht.probe(pair2.first),3);
    // //same h1 as pair1, and h2(k) = 7-12%7 = 2, so we probe in steps of 2 
    // // (i.e. 1 (collide), 3 (collide), 5 (open))
    // ht.insert(pair3);
    // // EXPECT_EQ(ht.probe(pair3.first),5);
    // //same hash as pair1, and h2(k) = 7-89%7 = 2, so we probe in steps of 2 
    // // (i.e. 1 (collide), 3 (collide), 5 (collide), 7 (open))
    // ht.insert(pair4);
    // // EXPECT_EQ(ht.probe(pair4.first),7);
    // //first item = loc = 2
    // ht.insert(pair5);
    // // EXPECT_EQ(ht.probe(pair5.first),2);
    // //same hash as pair5, and h2(k) = 7-46%7 = 3, so we probe in steps of 3 
    // // (i.e. 2 (collide with 2), 5 (collide with 12), 8 (open))
    // ht.insert(pair6);
    // // EXPECT_EQ(ht.probe(pair6.first),8);
    // // EXPECT_EQ(ht.size(),6);
    // cout << "HT SIZE" << ht.size() <<endl;
    // // EXPECT_TRUE(verifyItems(ht, items));




    // STRESS Insert
    // double loadfactor = 0.6;
    // const vector<int> sizemap = 
    // {
    //     11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421
    // };
    // HashTable<int, int, LinearProber<int>, IntHash2, equal_to<int>> ht(loadfactor, LinearProber<int>(), IntHash2()); 
    // set<pair<int, int>> items;
    // for(size_t i = 0;i<sizemap.size()-1;i++){
    //     int min = (int)floor(sizemap[i]*loadfactor);
    //     for(int j = 0; j<=min/2;j++){
    //         pair<int,int> pair(j,j);
    //         //insert then delete
    //         ht.insert(pair);
    //         ht.remove(j);
    //         EXPECT_TRUE(ht.find(j) == nullptr);
    //     }
    //     EXPECT_EQ(ht.size(),0);
    //     //reinsert the same pair, loc should change
    //     for(int j = 0; j<(min-(min/2));j++){
    //         pair<int,int> pair(j,j);
    //         //insert again
    //         ht.insert(pair);
    //         items.insert(pair);
    //         EXPECT_EQ(ht.probe(j),(min/2)+1+j);
    //     }
    //     EXPECT_EQ(ht.table_.size(),sizemap[i]);
    //     EXPECT_EQ(ht.size(),items.size());
    //     //add another should resize/rehash
    //     pair<int,int> pair((min/2)+1,(min/2)+1);
    //     ht.insert(pair);
    //     items.insert(pair);
    //     EXPECT_EQ(ht.table_.size(),sizemap[i+1]);
    //     EXPECT_EQ(ht.size(),items.size());
    //     //should be put into the correct spot, now that
    //     //the "deleted" items are actually "deleted" when resizing
    //     for(int j = 0; j<=(min/2+1);j++){
    //         EXPECT_EQ(ht.probe(j),j);
    //     }
    // }
    // EXPECT_TRUE(verifyItems(ht, items));
}
