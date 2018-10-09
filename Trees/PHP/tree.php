<?php

	abstract class Node {
		public function __construct($val)
		{
			$this->val = $val;
		}

		public function getKey()
		{
			return $this->val;
		}

		public function printKey()
		{
			echo $this->val . "\n";
		}

		private $val;

	}

	class ListNode extends Node {

		public function setNextNode($node)
		{
			$this->nextNode = $node;	
		}		

		public function getNextNode() 
		{
			return $this->nextNode;
		}

		private $nextNode = NULL;
	}



	abstract class LinkedList
	{
		protected function setHead($node)
		{
			$this->head = $node;		
		}

		protected function getHead()
		{
			return $this->head;
		}

		public function isEmpty()
		{
			$emptyList = false;

			if ( $this->getHead() == NULL )
			{
				$emptyList = true;
			}

			return $emptyList;
		}


		private $head;

	}	

	class Stack extends LinkedList
	{
		public function push($val)
		{
			$tmpNode = new ListNode($val);

			if ( $this->getHead() == NULL )
			{
				$this->setHead($tmpNode);	
			}
			else
			{
				$tmpNode->setNextNode($this->getHead());

				$this->setHead($tmpNode);
			}
		}

		public function pop()
		{
			if( $this->isEmpty())
			{
				return;
			}
			$tmpNode = $this->getHead();

			$this->setHead($tmpNode->getNextNode());

			return $tmpNode->getKey();

		}

		public function peek()
		{
			echo $this->getHead()->getKey()->getKey() . "\n";
		}
	}

	class BinaryNode extends Node {

		public function setLeftChild($node)
		{
			$this->leftChild = $node;
		}

		public function getLeftChild()
		{
			return $this->leftChild;
		}
		
		public function setRightChild($node)
		{
			$this->rightChild = $node;
		}

		public function getRightChild()
		{
			return $this->rightChild;
		}

		public function setParentNode($node)
		{
			$this->parentNode = $node;
		}

		public function getParentNode()
		{
			return $this->parentNode;
		}

		public function hasParent()
		{
			$hasParent = false;

			if ( $this->getParentNode() != NULL )
			{
				$hasParent = true;
			}

			return $hasParent;
		}

		public function hasChildren()
		{
			$hasChildren = false;

			if ( $this->getLeftChild() != NULL || $this->getRightChild() != NULL )
			{
				$hasChildren == true;
			}

			return $hasChildren;
				
		}

		private $leftChild = NULL;
		private $rightChild = NULL;
		private $parentNode = NULL;
	}


	abstract class Tree 
	{

		public function __construct()
		{
			$this->rootNode = NULL;
		}	

		public function getRoot()
		{
			return $this->rootNode;
		}

		protected function setRoot($node)
		{
			$this->rootNode = $node;
		}

		protected function checkIfLeaf($node)
		{
			$isLeaf = true;

			if ( $node->hasChildren() )
			{
				$isLeaf = false;
			}

			return $isLeaf;
		}
		
		private $rootNode;
	}

	class BST extends Tree 
	{
		protected function insertLeftSubTree($current, $node)
		{
			$node->setParentNode($current);
			$current->setLeftChild($node);

		}

		protected function insertRightSubTree($current, $node)
		{
			$node->setParentNode($current);
			$current->setRightChild($node);
		}

		protected function getRightTreeOf($current)
		{
			return $current->getRightChild();	
		}

		protected function getLeftTreeOf($current)
		{
			return $current->getLeftChild();
		}

		protected function getParentOf($current)
		{
			return $current->getParentNode();
		}

		//TRAVERSALS
		//

		public function inOrderTraversal()
		{
			$nodeStack = new Stack();

			$current = $this->getRoot();

			if ( $current == NULL )
			{
				return;
			}
			while (true)
			{
				if ( $current != NULL )
				{
					$nodeStack->push($current);
					$current = $this->getLeftTreeOf($current);
				}
				else
				{
					if ( $nodeStack->isEmpty() )
					{
						break;	
					}
					$current = $nodeStack->pop();
					$current->printKey();

					$current = $this->getRightTreeOf($current);
				}
			}
		}



		//Consider making this abstract and impement it sub classes
	
		public function insert($val)
		{
			$newNode = new BinaryNode($val);
			$root = $this->getRoot();

			$traverse=true;

			if ( $root == NULL )
			{
				$this->setRoot($newNode);
			}
			else
			{
				while($traverse)
				{
					if ($newNode->getKey() < $root->getKey())
					{
						if ( $this->getLeftTreeOf($root) == NULL )
						{
							$this->insertLeftSubTree($root, $newNode);

							$traverse = false;
						}	
						else
						{
							$root = $this->getLeftTreeOf($root);
						}
					}
					else
					{
						if ( $this->getRightTreeOf($root) == NULL )
						{
							$this->insertRightSubTree($root, $newNode);

							$traverse = false;
						}	
						else
						{
							$root = $this->getRightTreeOf($root);
						}
					}
				}
			}
		}
	}

	$BST = new BST();

	$BST->insert(7);
	$BST->insert(4);
	$BST->insert(12);
	$BST->insert(2);
	$BST->insert(3);
	$BST->insert(8);
	$BST->insert(15);

	$BST->inOrderTraversal();


?>
