#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

#include "binaryTree.hpp"

using namespace std;

template <class T>
class sewNode : public Node<T>
{
  public:
    bool l_flag;
    bool r_flag;

    sewNode() : Node<T>()
    {
      l_flag = true;
      r_flag = true;
    }

    sewNode(T data) : Node<T>(data)
    {
      l_flag = true;
      r_flag = true;
    }
};

template <class T>
class sewTree : public BinaryTree<T>
{
  protected:
    
    sewNode<T>* head = new sewNode<T>();
    sewNode<T>* p_old;

    // void left_sew(sewNode<T>* p, string detour)
    // {
    //   if (!p) return;
    //   for (int i = 0; i < 3; i++)
    //   {
    //     switch (detour[i])
    //     {
    //       case 'K':
    //       {
    //         if (p->left) p->l_flag = true;
    //         else
    //         {
    //           p->l_flag = false;
    //           p->left = p_old;
    //         }
    //         p_old = p;
    //         break;
    //       }
    //       case 'L':
    //       {
    //         left_sew(static_cast<sewNode<T>*>(p->left), detour);
    //         break;
    //       }
    //       case 'P':
    //       {
    //         left_sew(static_cast<sewNode<T>*>(p->right), detour);
    //         break;
    //       }
    //     }
    //   }
    //   return;
    // }

    // void right_sew(sewNode<T>* p, string detour)
    // {
    //   if (!p) return;
    //   for (int i = 0; i < 3; i++)
    //   {
    //     switch (detour[i])
    //     {
    //       case 'K':
    //       {
    //         if (p->right) p->r_flag = true;
    //         else
    //         {
    //           p->r_flag = false;
    //           p->right = p_old;
    //         }
    //         p_old = p;
    //         break;
    //       }
    //       case 'L':
    //       {
    //         right_sew(static_cast<sewNode<T>*>(p->right), detour);
    //         break;
    //       }
    //       case 'P':
    //       {
    //         if (p->l_flag) right_sew(static_cast<sewNode<T>*>(p->left), detour);
    //         break;
    //       }
    //     }
    //   }
    //   return;
    // }

    void left_sew_base(sewNode<T>* p)
    {
      if (!p) return;
      left_sew_base(static_cast<sewNode<T>*>(p->left));

      if (p->left) p->l_flag = true;
      else
      {
        p->l_flag = false;
        p->left = p_old;
      }
      p_old = p;

      left_sew_base(static_cast<sewNode<T>*>(p->right));
      return;
    }

    void right_sew_base(sewNode<T>* p)
    {
      if (!p) return;
      right_sew_base(static_cast<sewNode<T>*>(p->right));

      if (p->right) p->r_flag = true;
      else
      {
        p->r_flag = false;
        p->right = p_old;
      }
      p_old = p;

      if (p->l_flag) right_sew_base(static_cast<sewNode<T>*>(p->left));
      return;
    }

  public:

    sewTree(BinaryTree<T>* AVL_tree)
    {
      root = get_root(AVL_tree);
      BinaryTree<T>::root = BinaryTree<T>::get_root(AVL_tree);
    }

    // void sew(string detour)
    // {
    //   head->left = BinaryTree<T>::root;
    //   head->right = head;

    //   p_old = head;
    //   sewNode<T>* p = static_cast<sewNode<T>*>(head->left);
    //   left_sew(p, detour);

    //   p_old = head;
    //   p = static_cast<sewNode<T>*>(head->left);

    //   char tmp = detour[0];
    //   detour[0] = detour[2];
    //   detour[2] = tmp;

    //   right_sew(p, detour);
    // }

    // void sew_print(string detour)
    // {
    //   cout << detour << " print: ";
    //   sewNode<T>* p = static_cast<sewNode<T>*>(head->left);
    //   bool skip = false;

    //   if (detour[1] == 'K')
    //   {
    //     while (p != head)
    //     {
    //       if (!skip) while(p->l_flag) p = static_cast<sewNode<T>*>(p->left);
    //       skip = false;
    //       cout << p->key << " ";
    //       if (!p->r_flag) 
    //       {
    //         p = static_cast<sewNode<T>*>(p->right);
    //         skip = true;
    //       } else {
    //         p = static_cast<sewNode<T>*>(p->right);
    //       }
    //     }
    //   }
    // }

    void sew_base()
    {
      head->left = BinaryTree<T>::root;
      head->right = head;

      p_old = head;
      sewNode<T>* p = static_cast<sewNode<T>*>(head->left);
      left_sew_base(p);

      p_old = head;
      p = static_cast<sewNode<T>*>(head->left);
      right_sew_base(p);
    }

    void print_base()
    {
      cout << "base_print: ";
      sewNode<T>* p = static_cast<sewNode<T>*>(head->left);

      bool skip = false;

      while (p != head)
      {
        if (!skip) while(p->l_flag) p = static_cast<sewNode<T>*>(p->left);
        skip = false;

        cout << p->key << " ";

        if (!p->r_flag) 
        {
          p = static_cast<sewNode<T>*>(p->right);
          skip = true;
        } else {
          p = static_cast<sewNode<T>*>(p->right);
        }
      }

      cout << endl;
    }
};