#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
  public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node()
    {
      left = nullptr;
      right = nullptr;
    }

    Node(T value)
    {
      data = value;
      left = nullptr;
      right = nullptr;
    }
};

template <class T>
class BinaryTree
{
  private:
    Node<T>* root;
    int size;

  public:

    BinaryTree()
    {
      root = nullptr;
      size = 0;
    }

    int GetSize()
    {
      return size;
    }

    bool ElemExist(T value)
    {
      if (!size) return false;
      Node<T>* ptr = root;
      while (ptr && ptr->data != value) 
      {
        if (value > ptr->data) ptr = ptr->right;
        else ptr = ptr->left;
		  }
      if (ptr == nullptr) return false;
      else return true;
    }

    void AddElem(T value)
    {
      //already exists
      if (ElemExist(value))
      {
        cout << "Already exists!" << endl;
        return;
      }
      // root not exist
      if (!size)
      {
        root = new Node<T>(value);
        size = 1;
        return;
      }
      //add
      Node<T>* ptr = root;
      while (true)
      {
        //right add
        if (value > ptr->data)
        {
          //not add, continue
          if (ptr->right != nullptr)
          {
            ptr = ptr->right;
          } else {
            ptr->right = new Node<T>(value);
            size++;
            return;
          }
        } else if (value < ptr->data)
        {
          //not add, continue
          if (ptr->left != nullptr)
          {
            ptr = ptr->left;
          } else {
            ptr->left = new Node<T>(value);
            size++;
            return;
          }
        }
      }
      cout << "smthng wrong..." << endl;
      return;
    }

    Node<T>** FindElem(T value)
    {
      Node<T>* ptr = root;
      Node<T>* prev_ptr = nullptr;
      //Find
      while (ptr->data != value)
      {
        if (value > ptr->data)
        {
          prev_ptr = ptr;
          ptr = ptr->right;
        } else {
          prev_ptr = ptr;
          ptr = ptr->left;
        }
      }
      Node<T>** res = new Node<T>*[2];
      res[0] = prev_ptr;
      res[1] = ptr;
      return res;
    }

    void DeleteElem(T value)
    {
      // Exists?
      if (!ElemExist(value))
      {
        cout << "Doesn't exist" << endl;
        return;
      }
      // Root delete?
      if (size == 1)
      {
        delete root;
        root = nullptr;
        size--;
        return;
		  }

      // Elem ptrs
      Node<T>** pointers = FindElem(value);
      Node<T>* prev_ptr = pointers[0];
      Node<T>* ptr = pointers[1];
      //1. both childs
      if (ptr->left != nullptr && ptr->right != nullptr)
      {
        //find minimum
        Node<T>* min_ptr = ptr->right;
        while (min_ptr->left != nullptr)
        {
          min_ptr = min_ptr->left;
        }
        //reset
        T tmp = min_ptr->data;
        DeleteElem(min_ptr->data);
        ptr->data = tmp;
        return;
      }
      //2. Right Child
      if (ptr->right != nullptr)
      {
        if (ptr->data == root->data)
        {
          root = ptr->right;
        } else {
          if (prev_ptr->left == ptr) prev_ptr->left = ptr->right;
          if (prev_ptr->right == ptr) prev_ptr->right = ptr->right;
        }
        size--;
        delete ptr;
        return;
      }
      //3. Left Child
      if (ptr->left != nullptr)
      {
        if (ptr->data == root->data)
        {
          root = ptr->left;
        } else {
          if (prev_ptr->left == ptr) prev_ptr->left = ptr->left;
          if (prev_ptr->right == ptr) prev_ptr->right = ptr->left;
        }
        size--;
        delete ptr;
        return;
      }
      //4. not childs
      if (ptr->left == nullptr && ptr->right == nullptr)
      {
        if (prev_ptr->right == ptr) prev_ptr->right = nullptr;
        if (prev_ptr->left == ptr) prev_ptr->left = nullptr;
        size--;
        delete ptr;
      }
    }

    void Print()
    {

      if (!size)
      {
        cout << "Empty!" << endl; 
        return;
      }

      cout << "Tree SIZE: " << size << endl;

      cout << "KLP: ";
      KLP_Print(root);
      cout << endl;

      cout << "KPL: ";
      KPL_Print(root);
      cout << endl;

      cout << "LPK: ";
      LPK_Print(root);
      cout << endl;

      cout << "LKP: ";
      LKP_Print(root);
      cout << endl;

      cout << "PLK: ";
      PLK_Print(root);
      cout << endl;

      cout << "PKL: ";
      PKL_Print(root);
      cout << endl;
    }

    void KLP_Print(Node<T>* node)
    {
      if (node == nullptr) return;
      cout << node->data << " ";
      KLP_Print(node->left);
      KLP_Print(node->right);
    }

    void KPL_Print(Node<T>* node)
    {
      if (node == nullptr) return;
      cout << node->data << " ";
      KPL_Print(node->right);
      KPL_Print(node->left);
    }

    void LPK_Print(Node<T>* node)
    {
      if (node == nullptr) return;
      LPK_Print(node->left);
      LPK_Print(node->right);
      cout << node->data << " ";
    }

    void LKP_Print(Node<T>* node)
    {
      if (node == nullptr) return;
      LKP_Print(node->left);
      cout << node->data << " ";
      LKP_Print(node->right);
    }

    void PLK_Print(Node<T>* node)
    {
      if (node == nullptr) return;
      PLK_Print(node->right);
      PLK_Print(node->left);
      cout << node->data << " ";
    }

    void PKL_Print(Node<T>* node)
    {
      if (node == nullptr) return;
      PKL_Print(node->right);
      cout << node->data << " ";
      PKL_Print(node->left);
    }

    // Сохранение в строку

    string StringSaveBase()
    {
      string res;
      return StringBaseRec(root, res);
    }

    string StringBaseRec(Node<T>* node, string res)
    {
      if (node == nullptr) return res;
      res = res + " " + to_string(node->data);
      res = StringBaseRec(node->left, res);
      res = StringBaseRec(node->right, res);
      return res;
    }

    string StringSaveChoose(int* seq)
    {
      string res;
      return StringChooseRec(root, res, seq);
    }

    string StringChooseRec(Node<T>* node, string res, int* seq)
    {
      // 0 - K
      // 1 - L
      // 2 - P

      for(int i = 0; i < 3; i++)
      {
        if (node == nullptr) return res;
        switch (seq[i])
        {
          case 0:
          {
            res = res + " " + to_string(node->data);
            break;
          }
          case 1:
          {
            res = StringChooseRec(node->left, res, seq);
            break;
          }
          case 2:
          {
            res = StringChooseRec(node->right, res, seq);
            break;
          }
        }
      }
      return res;
    }


    //операции
    //MAP

    void Map(T (*func)(T data))
    {
      DetourMap(root, func);
    }

    void DetourMap(Node<T>* node, T (*func)(T data))
    {
      if (node == nullptr) return;
      node->data = func(node->data);
      DetourMap(node->left, func);
      DetourMap(node->right, func);
    }

    //Where

    void Where(bool (*func)(T value))
    {
      DetourWhere(root, func);
    }

    void DetourWhere(Node<T>* node, bool (*func)(T value))
    {
      if (node == nullptr) return;
      if (node != nullptr) DetourWhere(node->left, func);
      if (node != nullptr) DetourWhere(node->right, func);
      if (!func(node->data)) DeleteElem(node->data);
    }
    // при delete элемента с 2-мя детьми, сам элемент не удаляется, меняется лишь его значение
    
    // Reduce

    T Reduce(T (*func)(T val1, T val2), T constant)
    {
      T res = func(constant, DetourReduce(root, func));
      return res;
    }

    T DetourReduce(Node<T>* node, T (*func)(T val1, T val2))
    {
      if (node == nullptr) return 0;
      T res = func(node->data, DetourReduce(node->left, func));
      res = func(res, DetourReduce(node->right, func));
      return res;
    }

    //Merge
    void Merge(BinaryTree<T> tree2)
    {
      DetourMerge(tree2.root);
    }

    void DetourMerge(Node<T>* node)
    {
      if (node == nullptr) return;
      AddElem(node->data);
      DetourMerge(node->left);
      DetourMerge(node->right);
    }
  
    // Check Sub_Tree

    bool Check_SubTree(BinaryTree<T> tree3)
    {
      bool res = true;
      Node<T>** tmp_ptr = FindElem(tree3.root->data);
      res = Check_SubTreeRec(tmp_ptr[1], tree3.root, res);
      return res;
    }

    bool Check_SubTreeRec(Node<T>* t1_node, Node<T>* t2_node, bool res)
    {
      if (t2_node == nullptr) return res && true;
      if (t1_node == nullptr) return false;
      if (t2_node->data == t1_node->data)
      {
        res = res && true;
      } else {
        return false;
      }
      res = Check_SubTreeRec(t1_node->left, t2_node->left, res);
      res = Check_SubTreeRec(t1_node->right, t2_node->right, res);
      return res;
    }
/*

string StringBaseRec(Node<T>* node, string res)
    {
      if (node == nullptr) return res;
      res = res + " " + to_string(node->data);
      res = StringBaseRec(node->left, res);
      res = StringBaseRec(node->right, res);
      return res;
    }

*/
    //Get SubTree

    void GetSubTree(T value)
    {
      if (!ElemExist(value))
      {
        cout << "Doesn't exists" << endl;
        return;
      }
      BinaryTree<T>* subTree = new BinaryTree<T>;
      Node<T>** pointers = FindElem(value);
      DetourGetSubTree(pointers[1], subTree);
      subTree->Print();
    }

    void DetourGetSubTree(Node<T>* node, BinaryTree<T>* subTree)
    {
      if (node == nullptr) return;
      subTree->AddElem(node->data);
      DetourGetSubTree(node->left, subTree);
      DetourGetSubTree(node->right, subTree);
    }
    
    T* ToArray()
    {
      T *array = new T[size];
      DetourToArray(root, array);
      return array;
    }

    void DetourToArray(Node<T>* node, T* array)
    {
      if (node == nullptr) return;
      DetourToArray(node->left, array);
      *array = node->data;
      array++;
      DetourToArray(node->right, array);
    }
};