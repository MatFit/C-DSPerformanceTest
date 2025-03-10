#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "linear.hpp"
#include "tree.hpp"
#include "hashmap.hpp"
#include <vector>
#include <time.h>

// All this to be an unemployeed bum at the end fml

TEST_CASE("TESTS") {
    
    SECTION ("Test Data Structures Functionality"){
        // Simple functionality testing for data types int, double, and string 
        // Testing on data structures linear, binary tree, and hash table
        SECTION("Test Linear"){
            // Checks if elements are inserted through constructor
            SECTION("Test Instantiation") {
                    std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                    Linear linear(INTEGERS);
                    REQUIRE(linear.getSize() == 5);

                    std::vector<double> DOUBLES = {1.1, 2.2, 3.3, 4.4, 5.5};
                    Linear linear2(DOUBLES);
                    REQUIRE(linear2.getSize() == 5);

                    std::vector<char> CHARACTERS = {'a', 'b', 'c', 'd', 'e'};
                    Linear linear3(CHARACTERS);
                    REQUIRE(linear3.getSize() == 5);
            }
            // Checks if insertion method works as intended
            SECTION("Test Insertion") {
                std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                Linear linear(INTEGERS);
                linear.insertElement(6);
                
                REQUIRE(linear.getSize() == 6);
                REQUIRE(linear.search(6));

                // Double test
                std::vector<double> DOUBLES = {1.1, 2.2, 3.3, 4.4, 5.5};
                Linear linear2(DOUBLES);
                linear2.insertElement(6.6);
                
                REQUIRE(linear2.getSize() == 6);
                REQUIRE(linear2.search(6.6));


                // Character test
                std::vector<char> CHARACTERS = {'a', 'b', 'c', 'd', 'e'};
                Linear linear3(CHARACTERS);
                linear3.insertElement('f');
                
                REQUIRE(linear3.getSize() == 6);
                REQUIRE(linear3.search('f'));
            }
            // Checks to see if deletion method deletes as intended
            SECTION("Test Deletion") {
                // Integer test
                std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                Linear linear(INTEGERS);
                linear.deleteElement(3);
                REQUIRE(linear.getSize() == 4);
                REQUIRE(!linear.search(3));

                // Double test
                std::vector<double> DOUBLES = {1.1, 2.2, 3.3, 4.4, 5.5};
                Linear linear2(DOUBLES);
                linear2.deleteElement(3.3);
                REQUIRE(linear2.getSize() == 4);
                REQUIRE(!linear2.search(3.3));

                // Character test
                std::vector<char> CHARACTERS = {'a', 'b', 'c', 'd', 'e'};
                Linear linear3(CHARACTERS);
                linear3.deleteElement('c');
                REQUIRE(linear3.getSize() == 4);
                REQUIRE(!linear3.search('c'));
            }
            // Checks to see if search method find and doesn't find as intended
            SECTION("Test Search") {
                // Integer test
                std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                Linear linear(INTEGERS);
                REQUIRE(linear.search(3));
                REQUIRE(!linear.search(6));

                // Double test
                std::vector<double> DOUBLES = {1.1, 2.2, 3.3, 4.4, 5.5};
                Linear linear2(DOUBLES);
                REQUIRE(linear2.search(3.3));
                REQUIRE(!linear2.search(6.6));


                // Character test
                std::vector<char> CHARACTERS = {'a', 'b', 'c', 'd', 'e'};
                Linear linear3(CHARACTERS);
                REQUIRE(linear3.search('c'));
                REQUIRE(!linear3.search('f'));
            }
            // Checks if getter method at certain indexes works
            SECTION("Test getElementAtIndex") {
                // Integer test
                std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                Linear linear(INTEGERS);
                REQUIRE(linear.getElementAtIndex(2) == 3);

                // Double test
                std::vector<double> DOUBLES = {1.1, 2.2, 3.3, 4.4, 5.5};
                Linear linear2(DOUBLES);
                REQUIRE(linear2.getElementAtIndex(2) == 3.3);

                // Character test
                std::vector<char> CHARACTERS = {'a', 'b', 'c', 'd', 'e'};
                Linear linear3(CHARACTERS);
                REQUIRE(linear3.getElementAtIndex(2) == 'c');
                
            }
            // Tests overloading operator
            SECTION("Test operator<<") {
                // Integer test
                std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                Linear linear(INTEGERS);
                std::stringstream ss;
                ss << linear;

                REQUIRE(ss.str() == "1 2 3 4 5 "); // Extra space at the end naturally

                // Double test
                std::vector<double> DOUBLES = {1.1, 2.2, 3.3, 4.4, 5.5};
                Linear linear2(DOUBLES);
                std::stringstream ss2;
                ss2 << linear2;

                REQUIRE(ss2.str() == "1.1 2.2 3.3 4.4 5.5 ");

                // Character test
                std::vector<char> CHARACTERS = {'a', 'b', 'c', 'd', 'e'};
                Linear linear3(CHARACTERS);
                std::stringstream ss3;
                ss3 << linear3;

                REQUIRE(ss3.str() == "a b c d e ");
            }
        }
        // Tree testing
        SECTION ("Test Tree") {
            // Checks instantiation
            SECTION("Test Instantiation") {
                Tree<int> tree(1);
                REQUIRE(tree.getRoot()->val == 1);
            }
            // Checks deletion
            SECTION("Test Deletion") {
                Tree<int> tree(1);
                tree.~Tree();
                REQUIRE(tree.getRoot() == nullptr);
            }
            // Checks insertion
            SECTION("Test Insertion") {
                Tree<int> tree(1);
                tree.insertElement(0);
                tree.insertElement(2);
                tree.insertElement(3);
                tree.insertElement(4);
                tree.insertElement(5);
                REQUIRE(tree.getRoot()->left->val == 0);
                REQUIRE(tree.getRoot()->right->val == 2);
                REQUIRE(tree.getRoot()->right->right->val == 3);
                REQUIRE(tree.getRoot()->right->right->right->val == 4);
                REQUIRE(tree.getRoot()->right->right->right->right->val == 5);
            }
            // Checks funtional operator overload
            SECTION("Test Overload"){
                Tree<int> tree(1);
                tree.insertElement(0);
                tree.insertElement(2);
                tree.insertElement(3);
                tree.insertElement(4);
                tree.insertElement(5);
                tree.insertElement(6);
                std::stringstream ss;
                ss << tree;
                REQUIRE(ss.str() == "Tree: {0 1 2 3 4 5 6 }");
            }
        }
        // Test hashmap
        SECTION ("Test HashMap") {
            // Checks instantiation
            SECTION("Test Instantiation") {
                std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                HashMap<int> hashMap(INTEGERS, 10);
                REQUIRE(hashMap.getSize() == 10);
            }
            // Checks Insertion and the said inserted element is searchable
            SECTION("Test Insertion and Search") {
                std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                HashMap<int> hashMap(INTEGERS, 10);
                hashMap.insertElement(6);
                REQUIRE(hashMap.search(6));
            }
            // Checks Deletion and if said deleted item isn't searchable
            SECTION("Test Deletion and Search") {
                std::vector<int> INTEGERS = {1, 2, 3, 4, 5};
                HashMap<int> hashMap(INTEGERS, 10);
                hashMap.deleteElement(5);
                REQUIRE(!hashMap.search(5));
            }
            // Testing operator overload
            SECTION("Test Overloaded << Operator") {
                std::vector<int> values = {10, 20, 30, 40};
                HashMap<int> hashMap(values, 7);
            
                std::stringstream ss;
                ss << hashMap;
            
                std::string EXPECTED_OUTPUT =
                    "Bucket 0: empty\n"
                    "Bucket 1: empty\n"
                    "Bucket 2: 30\n"
                    "Bucket 3: 10\n"
                    "Bucket 4: empty\n"
                    "Bucket 5: 40\n"
                    "Bucket 6: 20\n";
            
                REQUIRE(ss.str() == EXPECTED_OUTPUT);
            }

        }
    }


    // Initializing file reader 
    std::ifstream intFile("integers.csv");
    std::ifstream doubleFile("decimals.csv");
    std::ifstream stringFile("strings.csv");

    SECTION("Compare Time Complexity"){
        // Distinguishing between data types
        SECTION("INTEGER"){
            
            std::cout << std::endl;
            std::cout << "INTEGER TIME TESTS:  " << std::endl;
            // ------------------------------------------------------------------------------ //
            std::cout << " ---- LINEAR INTEGER TIME COMPLEXITY ---" << std::endl;
            const int ITERATIONS = 100; // Testing complexity over several iterations because one aint enough
            double total_time = 0.0;

            std::string line;


            Linear<int> linear_test;
            Tree<int> tree_test;
            std::vector<int> numbers; 

            while (std::getline(intFile, line)) {
                int num = stoi(line);
                linear_test.insertElement(num);
                tree_test.insertElement(num);
                numbers.push_back(num);  // Save for search test
            }            

            std::cout << "Linear Structure Time Results (nanoseconds):" << std::endl;
            
            // Test search time for first single input
            for (int i = 0; i < ITERATIONS; ++i){                
                auto start = std::chrono::high_resolution_clock::now();
                linear_test.search(numbers[0]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }

            double linear_time_first = (total_time / ITERATIONS);
            std::cout << "Search for first input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;

            // Test search time for last single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                linear_test.search(numbers[numbers.size() - 1]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }

            double linear_time_last = (total_time / ITERATIONS);
            std::cout << "Search for last input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // // Test search time for random single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                int random_index = rand() % numbers.size();
                linear_test.search(numbers[random_index]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }

            double linear_time_random = (total_time / ITERATIONS);
            std::cout << "Search for random input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;
            // ------------------------------------------------------------------------------ //







            // ------------------------------------------------------------------------------ //
                std::cout << " ---- TREE INTEGER TIME COMPLEXITY ---" << std::endl;
                std::cout << "Tree Structure Time Results (nanoseconds):" << std::endl;
                
                // Test search time for first single input
                for (int i = 0; i < ITERATIONS; ++i){                
                    auto start = std::chrono::high_resolution_clock::now();
                    tree_test.search(numbers[0]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }

                double tree_time_first = (total_time / ITERATIONS);
                std::cout << "Tree for first input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;


                // Test search time for last single input
                for (int i = 0; i < ITERATIONS; ++i){
                    auto start = std::chrono::high_resolution_clock::now();
                    tree_test.search(numbers[numbers.size() - 1]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }

                double tree_time_last = (total_time / ITERATIONS);
                std::cout << "Tree for last input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;


                // // Test search time for random single input
                for (int i = 0; i < ITERATIONS; ++i){
                    auto start = std::chrono::high_resolution_clock::now();
                    int random_index = rand() % numbers.size();
                    tree_test.search(numbers[random_index]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }
                double tree_time_random = (total_time / ITERATIONS);
                std::cout << "Tree for random input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;
            // ------------------------------------------------------------------------------ //









            // ------------------------------------------------------------------------------ //
            std::cout << " ---- HASHTABLE INTEGER TIME COMPLEXITY ---" << std::endl;
            std::cout << "Hash table Structure Time Results (nanoseconds):" << std::endl;
            // Need to figure out how to construct default hashtable wait lol

            HashMap<int> hashmap(numbers, numbers.size());
            // Test search time for first single input
            for (int i = 0; i < ITERATIONS; ++i){                
                auto start = std::chrono::high_resolution_clock::now();
                hashmap.search(numbers[0]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }

            double hash_time_first = (total_time / ITERATIONS);
            std::cout << "Hash table for first input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // Test search time for last single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                hashmap.search(numbers[numbers.size() - 1]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }

            double hash_time_last = (total_time / ITERATIONS);
            std::cout << "Hash table for last input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // Test search time for random single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                int random_index = rand() % numbers.size();
                hashmap.search(numbers[random_index]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double hash_time_random = (total_time / ITERATIONS);
            std::cout << "Hash table for random input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;

            // ------------------------------------------------------------------------------ //



            // PERFORMANCE
            std::cout << "--- PERFORMANCE COMPARISON RESULTS ---" << std::endl;

            // Fancy if else statements
            std::cout << "FIRST Element - Fastest: " << 
                (hash_time_first <= tree_time_first && hash_time_first <= linear_time_first ? "Hash Table" :
                tree_time_first <= hash_time_first && tree_time_first <= linear_time_first ? "Tree" : "Linear") << std::endl;

            std::cout << "LAST Element - Fastest: " << 
                (hash_time_last <= tree_time_last && hash_time_last <= linear_time_last ? "Hash Table" :
                tree_time_last <= hash_time_last && tree_time_last <= linear_time_last ? "Tree" : "Linear") << std::endl;

            std::cout << "RANDOM Element - Fastest: " << 
                (hash_time_random <= tree_time_random && hash_time_random <= linear_time_random ? "Hash Table" :
                tree_time_random <= hash_time_random && tree_time_random <= linear_time_random ? "Tree" : "Linear") << std::endl;

            std::cout << std::endl;
            std::cout << std::endl;
        }
        SECTION("DECIMAL"){
            std::cout << "DOUBLE TIME TESTS:  " << std::endl;
            // ------------------------------------------------------------------------------ //
            std::cout << " ---- LINEAR DOUBLE TIME COMPLEXITY ---" << std::endl;
            const int ITERATIONS = 100; // Testing complexity over several iterations because one aint enough
            double total_time = 0.0;

            std::string line;


            Linear<double> linear_test;
            Tree<double> tree_test;
            std::vector<double> numbers; 

            while (std::getline(doubleFile, line)) {
                double num = stod(line);
                linear_test.insertElement(num);
                tree_test.insertElement(num);
                numbers.push_back(num);  // Save for search test
            }            

            std::cout << "Linear Structure Time Results (nanoseconds):" << std::endl;
            
            // Test search time for first single input
            for (int i = 0; i < ITERATIONS; ++i){                
                auto start = std::chrono::high_resolution_clock::now();
                linear_test.search(numbers[0]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double linear_time_first = total_time;
            std::cout << "Search for first input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;

            // Test search time for last single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                linear_test.search(numbers[numbers.size() - 1]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double linear_time_last = total_time;
            std::cout << "Search for last input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // // Test search time for random single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                int random_index = rand() % numbers.size();
                linear_test.search(numbers[random_index]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double linear_time_random = total_time;
            std::cout << "Search for random input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;
            // ------------------------------------------------------------------------------ //






            // ------------------------------------------------------------------------------ //
                std::cout << " ---- TREE DOUBLE TIME COMPLEXITY ---" << std::endl;
                std::cout << "Tree Structure Time Results (nanoseconds):" << std::endl;
                
                // Test search time for first single input
                for (int i = 0; i < ITERATIONS; ++i){                
                    auto start = std::chrono::high_resolution_clock::now();
                    tree_test.search(numbers[0]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }
                double tree_time_first = total_time;
                std::cout << "Tree for first input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;


                // Test search time for last single input
                for (int i = 0; i < ITERATIONS; ++i){
                    auto start = std::chrono::high_resolution_clock::now();
                    tree_test.search(numbers[numbers.size() - 1]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }
                double tree_time_last = total_time;
                std::cout << "Tree for last input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;


                // // Test search time for random single input
                for (int i = 0; i < ITERATIONS; ++i){
                    auto start = std::chrono::high_resolution_clock::now();
                    int random_index = rand() % numbers.size();
                    tree_test.search(numbers[random_index]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }
                double tree_time_random = total_time;
                std::cout << "Tree for random input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;
            // ------------------------------------------------------------------------------ //





            // ------------------------------------------------------------------------------ //
            std::cout << " ---- HASHTABLE DOUBLE TIME COMPLEXITY ---" << std::endl;
            std::cout << "Hash table Structure Time Results (nanoseconds):" << std::endl;
            // Need to figure out how to construct default hashtable wait lol

            HashMap<double> hashmap(numbers, numbers.size());
            // Test search time for first single input
            for (int i = 0; i < ITERATIONS; ++i){                
                auto start = std::chrono::high_resolution_clock::now();
                hashmap.search(numbers[0]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double hash_time_first = total_time;
            std::cout << "Hash table for first input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // Test search time for last single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                hashmap.search(numbers[numbers.size() - 1]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double hash_time_last = total_time;
            std::cout << "Hash table for last input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // // Test search time for random single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                int random_index = rand() % numbers.size();
                hashmap.search(numbers[random_index]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double hash_time_random = total_time;
            std::cout << "Hash table for random input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // PERFORMANCE
            std::cout << "--- PERFORMANCE COMPARISON RESULTS ---" << std::endl;

            // Fancy if else statements
            std::cout << "FIRST Element - Fastest: " << 
                (hash_time_first <= tree_time_first && hash_time_first <= linear_time_first ? "Hash Table" :
                tree_time_first <= hash_time_first && tree_time_first <= linear_time_first ? "Tree" : "Linear") << std::endl;

            std::cout << "LAST Element - Fastest: " << 
                (hash_time_last <= tree_time_last && hash_time_last <= linear_time_last ? "Hash Table" :
                tree_time_last <= hash_time_last && tree_time_last <= linear_time_last ? "Tree" : "Linear") << std::endl;

            std::cout << "RANDOM Element - Fastest: " << 
                (hash_time_random <= tree_time_random && hash_time_random <= linear_time_random ? "Hash Table" :
                tree_time_random <= hash_time_random && tree_time_random <= linear_time_random ? "Tree" : "Linear") << std::endl;

            std::cout << std::endl;
            std::cout << std::endl;
            
        }
        SECTION("STRING"){
            std::cout << "STRING TIME TESTS:  " << std::endl;
            // ------------------------------------------------------------------------------ //
            std::cout << " ---- LINEAR STRING TIME COMPLEXITY ---" << std::endl;
            const int ITERATIONS = 100; // Testing complexity over several iterations because one aint enough
            double total_time = 0.0;

            std::string line;


            Linear<std::string> linear_test;
            Tree<std::string> tree_test;
            std::vector<std::string> strings; 

            while (std::getline(stringFile, line)) {
                linear_test.insertElement(line);
                tree_test.insertElement(line);
                strings.push_back(line);
            }            

            std::cout << "Linear Structure Time Results (nanoseconds):" << std::endl;
            
            // Test search time for first single input
            for (int i = 0; i < ITERATIONS; ++i){                
                auto start = std::chrono::high_resolution_clock::now();
                linear_test.search(strings[0]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double linear_time_first = total_time;
            std::cout << "Search for first input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;

            // Test search time for last single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                linear_test.search(strings[strings.size() - 1]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double linear_time_last = total_time;
            std::cout << "Search for last input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // // Test search time for random single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                int random_index = rand() % strings.size();
                linear_test.search(strings[random_index]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double linear_time_random = total_time;
            std::cout << "Search for random input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;
            // ------------------------------------------------------------------------------ //






            // ------------------------------------------------------------------------------ //
                std::cout << " ---- TREE STRING TIME COMPLEXITY ---" << std::endl;
                std::cout << "Tree Structure Time Results (nanoseconds):" << std::endl;
                
                // Test search time for first single input
                for (int i = 0; i < ITERATIONS; ++i){                
                    auto start = std::chrono::high_resolution_clock::now();
                    tree_test.search(strings[0]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }

                double tree_time_first = total_time;
                std::cout << "Tree for first input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;


                // Test search time for last single input
                for (int i = 0; i < ITERATIONS; ++i){
                    auto start = std::chrono::high_resolution_clock::now();
                    tree_test.search(strings[strings.size() - 1]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }

                double tree_time_last = total_time;
                std::cout << "Tree for last input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;


                // // Test search time for random single input
                for (int i = 0; i < ITERATIONS; ++i){
                    auto start = std::chrono::high_resolution_clock::now();
                    int random_index = rand() % strings.size();
                    tree_test.search(strings[random_index]);
                    auto end = std::chrono::high_resolution_clock::now();
                    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                }
                double tree_time_random = total_time;
                std::cout << "Tree for random input in list: " << (total_time / ITERATIONS) << std::endl;
                total_time = 0.0;
            // ------------------------------------------------------------------------------ //




            
            // // ------------------------------------------------------------------------------ //
            std::cout << " ---- HASHTABLE STRING TIME COMPLEXITY ---" << std::endl;
            std::cout << "Hash table Structure Time Results (nanoseconds):" << std::endl;
            // Need to figure out how to construct default hashtable wait lol

            HashMap<std::string> hashmap(strings, strings.size());
            // Test search time for first single input
            for (int i = 0; i < ITERATIONS; ++i){                
                auto start = std::chrono::high_resolution_clock::now();
                hashmap.search(strings[0]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double hash_time_first = total_time;
            std::cout << "Hash table for first input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // Test search time for last single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                hashmap.search(strings[strings.size() - 1]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }
            double hash_time_last = total_time;
            std::cout << "Hash table for last input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;


            // // Test search time for random single input
            for (int i = 0; i < ITERATIONS; ++i){
                auto start = std::chrono::high_resolution_clock::now();
                int random_index = rand() % strings.size();
                hashmap.search(strings[random_index]);
                auto end = std::chrono::high_resolution_clock::now();
                total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            }

            double hash_time_random = total_time;
            std::cout << "Hash table for random input in list: " << (total_time / ITERATIONS) << std::endl;
            total_time = 0.0;

            
            // PERFORMANCE
            std::cout << "--- PERFORMANCE COMPARISON RESULTS ---" << std::endl;

            // Fancy if else statements
            std::cout << "FIRST Element - Fastest: " << 
                (hash_time_first <= tree_time_first && hash_time_first <= linear_time_first ? "Hash Table" :
                tree_time_first <= hash_time_first && tree_time_first <= linear_time_first ? "Tree" : "Linear") << std::endl;

            std::cout << "LAST Element - Fastest: " << 
                (hash_time_last <= tree_time_last && hash_time_last <= linear_time_last ? "Hash Table" :
                tree_time_last <= hash_time_last && tree_time_last <= linear_time_last ? "Tree" : "Linear") << std::endl;

            std::cout << "RANDOM Element - Fastest: " << 
                (hash_time_random <= tree_time_random && hash_time_random <= linear_time_random ? "Hash Table" :
                tree_time_random <= hash_time_random && tree_time_random <= linear_time_random ? "Tree" : "Linear") << std::endl;

            
        }
    }
}
