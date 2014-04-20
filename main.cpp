#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    tree T;
    node temp;
    int pil = 0, x = 0, key = 0;

    create_tree(&T);
    do {
        cout << "\nMENU\n";
        cout << "0. Load default data\n";
        cout << "1. Insert\n";
        cout << "2. Preorder\n";
        cout << "3. Inorder\n";
        cout << "4. Postorder\n";
        cout << "5. Search\n";
        cout << "6. Delete\n";
        cout << "7. Exit\n";
        cout << ">> ";
        cin >> pil;

        switch(pil) {
        case 0:
            insert_recursive(&(&T)->root, 50);
            insert_recursive(&(&T)->root, 17);
            insert_recursive(&(&T)->root, 72);
            insert_recursive(&(&T)->root, 12);
            insert_recursive(&(&T)->root, 23);
            insert_recursive(&(&T)->root, 54);
            insert_recursive(&(&T)->root, 76);
            insert_recursive(&(&T)->root, 9);
            insert_recursive(&(&T)->root, 14);
            insert_recursive(&(&T)->root, 19);
            insert_recursive(&(&T)->root, 67);
            cout << "Done.\n";
            break;
        case 1:
            cout << "Input number: ";
            cin >> x;
            insert_recursive(&(&T)->root, x);
            break;
        case 2:
            view_preorder(T.root);
            break;
        case 3:
            view_inorder(T.root);
            break;
        case 4:
            view_postorder(T.root);
            break;
        case 5:
            cout << "Masukkan angka: ";
            cin >> key;
            temp = search(T.root, key);
            if(temp != NULL) {
                cout << temp->info << endl;
            }
            break;
        case 6:
            cout << "Masukkan angka: ";
            cin >> key;
            deletion(&(&T)->root, NULL, key);
            break;
        }
    } while(pil != 7);
    return 0;
}
