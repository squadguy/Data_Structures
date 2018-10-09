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
			$tmpNode = $this->getHead();

			$this->setHead($tmpNode->getNextNode());

			return $tmpNode;

		}

		public function peek()
		{
			echo $this->getHead()->getKey();
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


	abstract class Tree {

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
			$current = $this->getRoot();
			$holdNode = NULL;

			while( $this->getLeftTreeOf($current) != NULL )
			{
				$current = $this->getLeftTreeOf($current);
			}
			echo $current->getKey();

			$current = $this->getParentOf($current);
			$holdNode = $current;
		}



		//Consider making this abstract and impement it sub classes
		public function insert($val)
		{
			$tmpNode = new BinaryNode($val);
			$current = $this->getRoot();
			$traverse = true;

			if ( $current == NULL )
			{
				$this->setRoot($tmpNode);		
			}	
			else
			{
				while ( $traverse )
				{
					if ( $current->getKey() > $tmpNode->getKey() )
					{
						if ( $this->checkIfLeaf($current) )
						{
							$this->insertLeftSubTree($current, $tmpNode);

							$traverse = false;
						}
						else 
						{
							$current = $this->getLeftTreeOf($current);;
						}
					}
					else
					{
						if ( $this->checkIfLeaf($current) )
						{
							$this->insertRightSubTree($current, $tmpNode);	

							$traverse = false;
						}
						else
						{
							$current = $this->getRightTreeOf($current);
						}
					}

				}
			}
		}
	}

	$BST = new BST();
	$BST->insert(5);
	$BST->insert(7);
	$BST->insert(4);


	/*
	echo $BST->getRoot()->getKey();
	echo $BST->getRoot()->getRightChild()->getParentNode()->getKey();
	echo $BST->getRoot()->getLeftChild()->getParentNode()->getKey();
	 */

//	$BST->inOrderTraversal();


?>
