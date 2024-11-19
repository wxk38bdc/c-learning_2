#pragma once
#include <iostream>
#include <cassert>

using namespace std;

//typedef enum
//{
//    RED = 0,
//    BLACK
//} Color;
//
////红黑树结点类型
//template <typename Type>
//struct RBTNode
//{
//    Color color;     //颜色
//    Type key;        //关键字
//    RBTNode* left;   //左孩子
//    RBTNode* right;  //右孩子
//    RBTNode* parent; //父结点
//};
//
////红黑树类型
//template <typename Type>
//class RBTree
//{
//public:
//    //构造函数
//    RBTree()
//    {
//        Nil = BuyNode();
//        root = Nil;
//        Nil->color = BLACK;
//    }
//    //析构函数
//    ~RBTree()
//    {
//        destroy(root); //销毁创建的非Nil结点
//        delete Nil;    //最后删除Nil结点
//        Nil = NULL;
//    }
//
//    //中序遍历
//    void InOrder() { InOrder(root); }
//
//    //插入
//    //1.BST方式插入
//    //2.调整平衡
//    bool Insert(const Type& value)
//    {
//        RBTNode<Type>* pr = Nil; //pr用来记住父节点
//        RBTNode<Type>* s = root; //定义变量s指向根
//        while (s != Nil)
//        {
//            if (value == s->key)
//            {
//                return false;
//            }
//            pr = s; //每次记住s的父节点
//            if (value < s->key)
//            {
//                s = s->left;
//            }
//            else
//            {
//                s = s->right;
//            }
//        }
//        //循环后s==Nil
//        s = BuyNode(value); //申请结点
//        if (pr == Nil)      //如果父节点pr是根节点，第一次root指向Nil，所以pr==Nil
//        {
//            root = s;
//            root->parent = pr;
//        }
//        else //如果父节点不是根节点
//        {
//            if (value < pr->key)
//            {
//                pr->left = s;
//            }
//            else
//            {
//                pr->right = s;
//            }
//            s->parent = pr; //设置新结点s的父节点
//        }
//        //调整平衡
//        Insert_Fixup(s);
//        return true;
//    }
//
//    //删除key结点(先查找，再调用内部删除)
//    void Remove(Type key)
//    {
//        RBTNode<Type>* t;
//        if ((t = Search(root, key)) != Nil)
//        {
//            Remove(t);
//        }
//    }
//
//	bool Find(const Type& key)
//	{
//		return Search(root, key) != Nil;
//	}
//
//    //中序遍历打印结点详细的结点颜色
//    void InOrderPrint() { InOrder(root); }
//
//private:
//    //申请结点结点，将结点的颜色初始化为红色，初始化结点的关键字，其他的初始化为空
//    RBTNode<Type>* BuyNode(const Type& x = Type())
//    {
//        RBTNode<Type>* s = new RBTNode<Type>();
//        assert(s != NULL);
//        s->color = RED;
//        s->left = s->right = s->parent = Nil;
//        s->key = x;
//        return s;
//    }
//
//    /* 左转，对z结点左转
//     *       zp                 zp
//     *       /                  /
//     *     z                   y
//     *    / \      ===>       / \
//     *   lz  y               z   ry
//     *      / \             / \
//     *     ly  ry          lz  ly
//     */
//    void LeftRotate(RBTNode<Type>* z)
//    {
//        RBTNode<Type>* y = z->right; //用y指向要转动的z结点
//        z->right = y->left;
//        if (y->left != Nil) //y所指结点的左结点不为空
//        {
//            y->left->parent = z;
//        }
//        y->parent = z->parent;
//        if (root == z) //z就是根节点
//        {
//            root = y;
//        }
//        else if (z == z->parent->left) //z在左结点
//        {
//            z->parent->left = y;
//        }
//        else //z在右结点
//        {
//            z->parent->right = y;
//        }
//        y->left = z;
//        z->parent = y;
//    }
//
//    /* 右转，对z结点进行右转
//    *         zp               zp
//    *        /                 /
//    *       z                 y
//    *      / \    ===>       / \
//    *     y   rz           ly   z
//    *    / \                   / \
//    *   ly  ry                ry  rz
//    */
//    void RightRotate(RBTNode<Type>* z)
//    {
//        RBTNode<Type>* y = z->left;
//        z->left = y->right;
//        if (y->right != Nil)
//        {
//            y->right->parent = z;
//        }
//        y->parent = z->parent;
//        if (root == z) //如果z是根结点
//        {
//            root = y;
//        }
//        else if (z == z->parent->left) //z在左结点
//        {
//            z->parent->left = y;
//        }
//        else //z在右结点
//        {
//            z->parent->right = y;
//        }
//        y->right = z;
//        z->parent = y;
//    }
//
//    //插入后的调整函数
//    void Insert_Fixup(RBTNode<Type>* s)
//    {
//        RBTNode<Type>* uncle;           //叔结点（父结点的兄弟结点）
//        while (s->parent->color == RED) //父节点的颜色也为红色
//        {
//            if (s->parent == s->parent->parent->left) //父节点是左结点
//            {
//                uncle = s->parent->parent->right;
//
//                if (uncle->color == RED) //叔结点为红色
//                {
//                    //父节点和叔结点都变为黑色
//                    s->parent->color = BLACK;
//                    uncle->color = BLACK;
//                    //祖父结点变为红色
//                    s->parent->parent->color = RED;
//                    //将s指针指向祖父结点，下一次循环继续判断祖父的父节点是否为红色
//                    s = s->parent->parent;
//                }
//                else //没有叔结点，或叔结点为黑色(经过多次循环转换，叔结点可能为黑)
//                {
//                    if (s == s->parent->right) //如果调整的结点在右结点
//                    {
//                        s = s->parent; //先将s指向s的父结点
//                        LeftRotate(s); //再左转
//                    }
//                    //如果调整的结点在左结点,将s的父节点变为黑色，将祖父的结点变为红色，将s的祖父结点右转
//                    s->parent->color = BLACK;
//                    s->parent->parent->color = RED;
//                    RightRotate(s->parent->parent);
//                }
//            }
//            else
//            {
//                if (s->parent == s->parent->parent->right) //父节点是右结点
//                {
//                    uncle = s->parent->parent->left;
//                    if (uncle->color == RED) //叔结点为红色
//                    {
//                        //父节点和叔结点都变为黑色
//                        s->parent->color = BLACK;
//                        uncle->color = BLACK;
//                        //祖父结点变为红色
//                        s->parent->parent->color = RED;
//                        //将s指针指向祖父结点，下一次循环继续判断祖父的父节点是否为红色
//                        s = s->parent->parent;
//                    }
//                    else //没有叔结点，或叔结点为黑色(经过多次循环转换，叔结点可能为黑)
//                    {
//                        if (s == s->parent->left) //如果调整的结点在左结点
//                        {
//                            s = s->parent;  //先将s指向s的父结点
//                            RightRotate(s); //再右转
//                        }
//                        //如果调整的结点在右结点,将s的父节点变为黑色，将祖父的结点变为红色，将s的祖父结点右转
//                        s->parent->color = BLACK;
//                        s->parent->parent->color = RED;
//                        LeftRotate(s->parent->parent);
//                    }
//                }
//            }
//        }
//        root->color = BLACK; //最后始终将根节点置为黑色
//    }
//
//    //查找key结点
//    RBTNode<Type>* Search(RBTNode<Type>* root, Type key) const
//    {
//        if (root == Nil) //root为空，或key和根的key相同
//        {
//            return Nil;
//        }
//
//        if (root->key == key)
//        {
//            return root;
//        }
//        if (key < root->key)
//        {
//            return Search(root->left, key);
//        }
//        else
//        {
//            return Search(root->right, key);
//        }
//    }
//
//    /* 将u的子节点指向u的指针改变指向v，将v的父节点指针改变为指向u的父节点
//     *      up
//     *        \
//     *         u
//     *        / \
//     *      ul   ur
//     *     / \
//     *    v  ulr
//     *     \
//     *     rv
//     */
//    void Transplant(RBTNode<Type>* u, RBTNode<Type>* v)
//    {
//        if (u->parent == Nil) //u的父节点为空
//        {
//            root = v; //直接令根root为v
//        }
//        else if (u == u->parent->left) //u父节点不为空，且u在左子树
//        {
//            u->parent->left = v;
//        }
//        else //u在右子树
//        {
//            u->parent->right = v;
//        }
//        v->parent = u->parent;
//    }
//
//    /* 找到最左结点(最小)
//     *      xp
//     *        \
//     *         x
//     *        / \
//     *      xl   xr
//     *     / \
//     *   xll  xlr
//     */
//    RBTNode<Type>* Minimum(RBTNode<Type>* x)
//    {
//        if (x->left == Nil)
//        {
//            return x;
//        }
//        return Minimum(x->left);
//    }
//
//    //删除红黑树结点z
//    void Remove(RBTNode<Type>* z)
//    {
//        RBTNode<Type>* x = Nil;
//        RBTNode<Type>* y = z;    //y记住传进来的z结点
//        Color ycolor = y->color; //
//        if (z->left == Nil)      //z只有右孩子
//        {
//            x = z->right;
//            Transplant(z, z->right);
//        }
//        else if (z->right == Nil) //z只有右孩子
//        {
//            x = z->left;
//            Transplant(z, z->left);
//        }
//        else //右左孩子和右孩子
//        {
//            y = Minimum(z->right); //y是z右子树的的最左子树
//            ycolor = y->color;
//            x = y->right;
//            if (y->parent == z) //z的右子结点没有左节点或为Nil
//            {
//                x->parent = y;
//            }
//            else //z的右子结点有左节点或为Nil
//            {
//                Transplant(y, y->right);
//                y->right = z->right;
//                y->right->parent = y;
//            }
//            Transplant(z, y);
//            //改变指向
//            y->left = z->left;
//            z->left->parent = y;
//            y->color = z->color;
//        }
//        if (ycolor == BLACK)
//        {
//            Remove_Fixup(x);
//        }
//    }
//
//    //红黑树删除调整
//    void Remove_Fixup(RBTNode<Type>* x)
//    {
//        while (x != root && x->color == BLACK) //当结点x不为根并且它的颜色不是黑色
//        {
//            if (x == x->parent->left) //x在左子树
//            {
//                RBTNode<Type>* w = x->parent->right; //w是x的兄结点
//
//                if (w->color == RED) //情况1
//                {
//                    w->color = BLACK;
//                    x->parent->color = RED;
//                    LeftRotate(x->parent);
//                    w = x->parent->right;
//                }
//                if (w->left->color == BLACK && w->right->color == BLACK) //情况2
//                {
//                    w->color = RED;
//                    x = x->parent;
//                }
//                else
//                {
//                    if (w->right->color == BLACK) //情况3
//                    {
//                        w->color = RED;
//                        w->left->color = BLACK;
//                        RightRotate(w);
//                        w = x->parent->right;
//                    }
//                    //情况4
//                    w->color = w->parent->color;
//                    w->parent->color = BLACK;
//                    w->right->color = BLACK;
//                    LeftRotate(x->parent);
//                    x = root; //结束循环
//                }
//            }
//            else //x在右子树
//            {
//                RBTNode<Type>* w = x->parent->left;
//                if (w->color == RED) //情况1
//                {
//                    w->parent->color = RED;
//                    w->color = BLACK;
//                    RightRotate(x->parent);
//                    w = x->parent->left;
//                }
//                if (w->right->color == BLACK && w->right->color == BLACK) //情况2
//                {
//                    w->color = RED;
//                    x = x->parent;
//                }
//                else
//                {
//                    if (w->left->color == BLACK) //情况3
//                    {
//                        w->right->color = BLACK;
//                        w->color = RED;
//                        LeftRotate(w);
//                        w = x->parent->left;
//                    }
//                    //情况4
//                    w->color = x->parent->color;
//                    x->parent->color = BLACK;
//                    w->left->color = BLACK;
//                    RightRotate(x->parent);
//                    x = root; //结束循环
//                }
//            }
//        }
//        x->color = BLACK;
//    }
//
//    //销毁红黑树
//    void destroy(RBTNode<Type>*& root)
//    {
//        if (root == Nil)
//        {
//            return;
//        }
//        if (root->left != Nil)
//        {
//            destroy(root->left);
//        }
//        if (root->right != Nil)
//        {
//            destroy(root->right);
//        }
//        delete root;
//        root = NULL;
//    }
//    //中序遍历
//    void InOrder(RBTNode<Type>* root)
//    {
//        if (root != Nil)
//        {
//            InOrder(root->left);
//            cout << root->key << " ";
//            InOrder(root->right);
//        }
//    }
//    //中序遍历打印结点详细的结点颜色
//    void InOrderWithColor(RBTNode<Type>* node)
//    {
//        if (node == Nil)
//        {
//            return;
//        }
//        if (node->left != NULL)
//        {
//            InOrderWithColor(node->left);
//        }
//        cout << node->key << "(" << ((node->color == BLACK) ? "B" : "R") << ")" << " ";
//        if (node->right != Nil)
//        {
//            InOrderWithColor(node->right);
//        }
//    }
//
//private:
//    RBTNode<Type>* root; //根指针
//    RBTNode<Type>* Nil;  //外部结点，表示空结点，黑色的
//};
//
//void testRBTree() {
//    RBTree<int> tree;
//    for (int i = 100; i > 0; i -= 2)
//        tree.Insert(i);
//    tree.InOrderPrint();
//    cout << endl;
//    for (int i = 2; i < 100; i += 4)
//        tree.Remove(i);
//    tree.InOrderPrint();
//    cout << endl;
//
//    for (int i = 0; i < 20; i++)
//    {
//        if (tree.Find(i))
//            cout << i << " found" << endl;
//        else
//            cout << i << " not found" << endl;
//    }
//}

#ifndef RBTREE_H__
#define RBTREE_H__

#include <iostream>
#include <memory>
#include <list>
#include <string>

using namespace std;
// red-black tree

const auto RED = 0;
const auto BLACK = 1;
const auto NULL_NODE = -100;
const auto LEFT_CHILD = 0;
const auto RIGHT_CHILD = 1;

template<typename T>
class rb_tree_node
{
public:
	rb_tree_node(const T& data, int color)
		: data_(data)
		, color_(color)
		, parent_(nullptr)
		, l_child_(nullptr)
		, r_child_(nullptr)
	{

	}

public:
	T		data_;
	int		color_;
	rb_tree_node* parent_;
	rb_tree_node* l_child_;
	rb_tree_node* r_child_;
};

template<typename T>
class RBTree
{
public:
	typedef T			value_type;
	typedef const value_type& const_ref_type;
	typedef rb_tree_node<T>		node_value_type;
	typedef rb_tree_node<T>* node_pointer;
	typedef const node_pointer	const_node_pointer;

public:
	RBTree(): root_(nullptr){}

	int Insert(const_ref_type data)
	{
		if (nullptr == this->root_)
		{
			this->root_ = new node_value_type(data, BLACK);
			return 0;
		}

		return insert_node(nullptr, LEFT_CHILD, this->root_, data);
	}

	int Remove(const_ref_type data)
	{
		if (nullptr == this->root_)
			return -1;
		return erase_node(nullptr, LEFT_CHILD, this->root_, data);
	}

	void InOrderPrint()
	{
		mid_visit_node(this->root_);
	}
	//void dump()
	//{
	//	mid_visit_node(this->root_);
	//}

	bool Find(const_ref_type data)
	{
		node_pointer p = this->root_;
		while (p)
		{
			if (data == p->data_)
				return true;
			else if (data < p->data_)
				p = p->l_child_;
			else
				p = p->r_child_;
		}
		return false;
	}

	int height()
	{
		return this->height_i(this->root_);
	}

	void check_rb_feature_5()
	{
		std::list<int> list;
		char trace[100] = { 0 };
		check_rb_feature_5_impl(nullptr, this->root_, trace, 0, list);
		int len = -1;
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (-1 == len)
				len = *it;
			else if (len != *it)
			{
				std::cout << "check_rb_feature_5 failed: " << std::endl;
				return;
			}
		}

		std::cout << "check_rb_feature_5 success, black node count:  " << len << std::endl;
	}

private:
	int insert_node(node_pointer pp, int pp_child_tag, node_pointer p, const_ref_type data)
	{
		if (nullptr == p)
		{
			p = new node_value_type(data, RED);
			LEFT_CHILD == pp_child_tag ? pp->l_child_ = p : pp->r_child_ = p;
			p->parent_ = pp;
			if (RED == pp->color_)
				this->adjust_balance(p);
			return 0;
		}
		else if (p->data_ == data)
			return -1;
		else if (data < p->data_)
			return this->insert_node(p, LEFT_CHILD, p->l_child_, data);
		else
			return this->insert_node(p, RIGHT_CHILD, p->r_child_, data);
	}

	int erase_node(node_pointer pp, int pp_child_tag, node_pointer p, const_ref_type data)
	{
		if (nullptr == p)
			return -1;
		else if (p->data_ == data)
		{
			node_pointer fake_null = nullptr;
			int delete_node_color = p->color_;
			node_pointer& ref_p = (pp ? (LEFT_CHILD == pp_child_tag ? pp->l_child_ : pp->r_child_) : this->root_);

			if (p->l_child_ && p->r_child_)
			{
				auto prev = p->l_child_;
				auto curr = prev;
				for (; curr && curr->r_child_; prev = curr, curr = curr->r_child_);
				delete_node_color = curr->color_;
				if (curr == prev)
				{
					p->data_ = curr->data_;
					p->l_child_ = curr->l_child_;
					if (curr->l_child_)
						curr->l_child_->parent_ = p;
					pp = p;
					p = p->l_child_;
					pp_child_tag = LEFT_CHILD;
					delete curr;
				}
				else
				{
					p->data_ = curr->data_;
					pp = prev;
					pp_child_tag = RIGHT_CHILD;
					p = prev->r_child_ = curr->l_child_;
					if (curr->l_child_)
						curr->l_child_->parent_ = prev;
					delete curr;
				}
			}
			else if (p->l_child_)
			{
				ref_p = p->l_child_;
				p->l_child_->parent_ = pp;
				delete p;
				p = ref_p;
			}
			else if (p->r_child_)
			{
				ref_p = p->r_child_;
				p->r_child_->parent_ = pp;
				delete p;
				p = ref_p;
			}
			else
			{
				p = ref_p = nullptr;
			}

			if (BLACK == delete_node_color && pp)
			{
				if (nullptr == p)
				{
					fake_null = p = new node_value_type(NULL_NODE, BLACK);
					p->parent_ = pp;
					LEFT_CHILD == pp_child_tag ? pp->l_child_ = p : pp->r_child_ = p;
				}

				this->adjust_delete_balance(pp, p);
				if (fake_null)
				{
					if (fake_null->parent_->l_child_ == fake_null)
						fake_null->parent_->l_child_ = nullptr;
					else
						fake_null->parent_->r_child_ = nullptr;
					delete fake_null;
				}
			}
			return 0;
		}
		else if (data < p->data_)
			return this->erase_node(p, LEFT_CHILD, p->l_child_, data);
		else
			return this->erase_node(p, RIGHT_CHILD, p->r_child_, data);
	}

private:
	void adjust_balance(node_pointer p)
	{
		while (p->parent_ && p->parent_->parent_ && RED == p->parent_->color_)
		{
			auto pp = p->parent_;
			auto gp = pp->parent_;
			auto up = (gp->l_child_ == pp ? gp->r_child_ : gp->l_child_);
			if (gp->l_child_ == pp)
			{
				if (up && RED == up->color_)
				{
					pp->color_ = up->color_ = BLACK;
					gp->color_ = RED;
					p = gp;
				}
				else
				{
					if (pp->r_child_ == p)
					{
						this->l_rotate(pp);
						swap(p, pp);
					}

					pp->color_ = BLACK;
					gp->color_ = RED;
					this->r_rotate(gp);
				}
			}
			else
			{
				if (up && RED == up->color_)
				{
					pp->color_ = up->color_ = BLACK;
					gp->color_ = RED;
					p = gp;
				}
				else
				{
					if (pp->l_child_ == p)
					{
						this->r_rotate(pp);
						swap(p, pp);
					}

					pp->color_ = BLACK;
					gp->color_ = RED;
					this->l_rotate(gp);
				}
			}
		}

		this->root_->color_ = BLACK;
	}

	void adjust_delete_balance(node_pointer pp, node_pointer p)
	{
		while ((nullptr == p || BLACK == p->color_) && p != this->root_)
		{
			if (pp->l_child_ == p)
			{
				auto s = pp->r_child_;
				if (s && RED == s->color_)
				{
					s->color_ = BLACK;
					pp->color_ = RED;
					this->l_rotate(pp);
					s = pp->r_child_;
				}

				if ((nullptr == s->l_child_ || BLACK == s->l_child_->color_)
					&& (nullptr == s->r_child_ || BLACK == s->r_child_->color_))
				{
					s->color_ = RED;
					p = pp;
					pp = p->parent_;
				}
				else
				{
					if (nullptr == s->r_child_ || BLACK == s->r_child_->color_)
					{
						s->l_child_ ? s->l_child_->color_ = BLACK : 0;
						s->color_ = RED;
						this->r_rotate(s);
						s = pp->r_child_;
					}

					s->color_ = pp->color_;
					pp->color_ = BLACK;
					s->r_child_->color_ = BLACK;
					this->l_rotate(pp);
					p = this->root_;
				}
			}
			else
			{
				auto s = pp->l_child_;
				if (s && RED == s->color_)
				{
					s->color_ = BLACK;
					pp->color_ = RED;
					this->r_rotate(pp);
					s = pp->l_child_;
				}

				if ((nullptr == s->l_child_ || BLACK == s->l_child_->color_)
					&& (nullptr == s->r_child_ || BLACK == s->r_child_->color_))
				{
					s->color_ = RED;
					p = pp;
					pp = p->parent_;
				}
				else
				{
					if (nullptr == s->l_child_ || BLACK == s->l_child_->color_)
					{
						s->r_child_ ? s->r_child_->color_ = BLACK : 0;
						s->color_ = RED;
						this->l_rotate(s);
						s = pp->l_child_;
					}

					s->color_ = pp->color_;
					pp->color_ = BLACK;
					s->l_child_->color_ = BLACK;
					this->r_rotate(pp);
					p = this->root_;
				}
			}
		}

		p->color_ = BLACK;
	}

private:
	node_pointer l_rotate(node_pointer p)
	{
		auto lr = p->r_child_;
		p->r_child_ = lr->l_child_;
		if (lr->l_child_)
			lr->l_child_->parent_ = p;

		lr->parent_ = p->parent_;
		if (nullptr == p->parent_)
			this->root_ = lr;
		else if (p->parent_->l_child_ == p)
			p->parent_->l_child_ = lr;
		else
			p->parent_->r_child_ = lr;

		lr->l_child_ = p;
		p->parent_ = lr;

		return lr;
	}

	node_pointer r_rotate(node_pointer p)
	{
		auto lc = p->l_child_;
		p->l_child_ = lc->r_child_;
		if (lc->r_child_)
			lc->r_child_->parent_ = p;

		lc->parent_ = p->parent_;
		if (nullptr == p->parent_)
			this->root_ = lc;
		else if (p->parent_->l_child_ == p)
			p->parent_->l_child_ = lc;
		else
			p->parent_->r_child_ = lc;

		lc->r_child_ = p;
		p->parent_ = lc;

		return lc;
	}

	int height_i(node_pointer p)
	{
		if (nullptr == p)
			return 0;

		int left_height = 0;
		if (p->l_child_)
			left_height = height_i(p->l_child_) + 1;

		int right_height = 0;
		if (p->r_child_)
			right_height = height_i(p->r_child_) + 1;

		return left_height >= right_height ? left_height : right_height;
	}

	void mid_visit_node(const_node_pointer p)
	{
		if (nullptr != p)
		{
			mid_visit_node(p->l_child_);
			std::cout << p->data_ << std::endl;
			mid_visit_node(p->r_child_);
		}
	}

	void check_rb_feature_5_impl(node_pointer pp, node_pointer p, char trace[], int idx, std::list<int>& list)
	{
		if (nullptr == p)
		{
			trace[idx] = BLACK;
			int result = 0;
			for (auto k = 0; k <= idx; ++k)
			{
				if (BLACK == trace[k])
					++result;
			}

			list.push_back(result);
		}
		else
		{
			trace[idx] = p->color_;
			check_rb_feature_5_impl(p, p->l_child_, trace, idx + 1, list);
			check_rb_feature_5_impl(p, p->r_child_, trace, idx + 1, list);
		}
	}

private:
	node_pointer	root_;
};

#endif