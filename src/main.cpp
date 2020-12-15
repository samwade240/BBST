#include<bits/stdc++.h>
#include "binarytree.hpp"
using namespace std;

int main()
{

   AVLTree<int> tree;
   std::string temp;

   //Constructing tree given in
    //the above figure
    tree.put(9);
    tree.put(5);
    tree.put(10);
    tree.put(0);
    tree.put(6);
    tree.put(11);
    tree.put(-1);
    tree.put(1);
    tree.put(2);
    AVLTree<int> secondTree(tree);

//     The constructed AVL Tree would be
//            9
//           / \
//          1   10
//         / \    \
//         0  5   11
//        /  / \
//      -1  2   6


    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    temp = tree.preorderString();
    cout << temp <<"\n";
    cout << tree.getHeight() <<"\n";

    cout << "Preorder traversal of the "
            "copied AVL tree is \n";
    temp = secondTree.preorderString();
    cout << temp <<"\n";
    cout << secondTree.getHeight() <<"\n";

    cout << "INorder traversal of the "
            "constructed AVL tree is \n";
    temp = tree.inorderString();
    cout << temp <<"\n";
    cout << tree.getHeight() <<"\n";

    cout << "Postorder traversal of the "
            "constructed AVL tree is \n";
    temp = tree.postorderString();
    cout << temp <<"\n";
    cout << tree.getHeight() <<"\n";

    tree.remove(10);

//     The AVL Tree after deletion of 10
//            1
//           / \
//          0   9
//         /   / \
//        -1  5   11
//        / \
//        2 6

    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    temp = tree.preorderString();
    cout << temp <<"\n";
    cout << tree.getHeight() <<"\n";
    cout <<"Contains 2 should be true: " <<tree.contains(2)<<"\n";

    cout << "\nPreorder traversal after"
         << " deletion of 2 and 6 \n";
	tree.remove(2);
	tree.remove(6);
    temp = tree.preorderString();
    cout << temp <<"\n";
    cout << tree.getHeight() <<"\n";
    cout <<"Contains 2 should be false: " <<tree.contains(2)<<"\n";


    cout << "\nStarting Treap Tree: \n";

    TreapTree<int> treap;
    std::string tmp;

    srand(time(NULL));

    treap.put(50);
    treap.put(30);
    treap.put(20);
    treap.put(40);
    treap.put(70);
    treap.put(60);
    treap.put(80);

//    TreapTree<int> secondTreap(treap);

    cout << "preorderString traversal of the given tree \n";
    tmp = treap.preorderString();
    cout << tmp << "\n";

//    cout << "preorderString traversal of the copied tree \n";
//    tmp = secondTreap.preorderString();
//    cout << tmp << "\n";

    cout << "inorderString traversal of the given tree \n";
    tmp = treap.inorderString();
    cout << tmp << "\n";

    cout << "postorderString traversal of the given tree \n";
    tmp = treap.postorderString();
    cout << tmp << "\n";

    cout << "\nDelete 20\n";
    treap.remove(20);
    cout << "postorderString traversal of the modified tree \n";
    tmp = treap.postorderString();
    cout << tmp << "\n";

    cout << "\nDelete 30\n";
    treap.remove(30);
    cout << "postorderString traversal of the modified tree \n";
    tmp = treap.postorderString();
    cout << tmp << "\n";

    cout << "\nDelete 50\n";
    treap.remove(50);
    cout << "postorderString traversal of the modified tree \n";
    tmp = treap.postorderString();
    cout << tmp << "\n";


    TreapNode<int> *res = treap.search(50);
    (res == NULL)? cout << "\n50 Not Found ":
                   cout << "\n50 found";





/*
   TreapTree<int> treap;
   AVLTree<int> tree2;


    //Inserting elements of I to delete in the timed for loop
//    for(int i = 1000; i < 10000; i += 1000){
    for(int i = 1000; i < 10000; i += 100){
	tree2.put(i);
	treap.put(i);
    }

//     clock_t is the data type for storing timing information.
//     * We must make two variables, one for the start and the other to capture
//     * the difference.

    clock_t start, diff;

    // timeAmount is used to print out the time in seconds.
    double timeAmount;

    // We want to run our algorithm over varying sizes.
    for (int i = 1000; i < 10000; i += 1000) {
        // Capture the start clock
        start = clock();

        // This is were your algorithm should be called.
        // Keep in mind that i is the SIZE of the input -- you may have to change it!

//	tree2.put(i);
//      treap.put(i);
	tree2.remove(i);
//	treap.remove(i);


        // Capture the clock and subtract the start to get the total time elapsed.
        diff = clock() - start;

        // Convert clock_t into seconds as a floating point number.
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;

        // Print out first the size (i) and then the elapsed time.
        std::cout << i << " " << timeAmount << "\n";

        // We flush to ensure the timings is printed out.
        std::cout << std::flush;
    }

*/





    return 0;
}
