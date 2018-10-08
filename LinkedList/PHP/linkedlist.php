<?php

class node {

	public function __construct($val)
	{
		$this->val = $val;
		$this->nextNode = NULL;
	}

	public function printVal()
	{
		if ( $this->getNext() == NULL )
		{
			echo $this->val . "\n";
		}
		else
		{
			echo $this->val . "->";
		}
	}

	public function getNext()
	{
		return $this->nextNode;
	}

	public function setNext($node)
	{
		$this->nextNode = $node;
	}

	private $val;
	private $nextNode = NULL;
}

class linkedList{

	public function setHead($node)
	{
		$this->head = $node;
	}

	public function setTail($node)
	{
		$this->tail = $node;
	}

	public function getHead()
	{
		return $this->head;
	}

	public function getTail()
	{
		return $this->tail;
	}

	public function push($node)
	{
		$tmp = new node($node);

		if ( $this->getHead() == NULL )
		{
			$this->setHead($tmp);
			$this->setTail($tmp);
		}
		else
		{
			$this->getTail()->setNext($tmp);
			$this->setTail($tmp);
		}
	}

	public function enqueue($node)
	{
		$tmp = new node($node);

		if ( $this->getHead() == NULL )
		{
			$this->setHead($tmp);
			$this->setTail($tmp);
		}
		else
		{
			$tmp->setNext($this->getHead());
			$this->setHead($tmp);
		}
	}

	public function printList()
	{
		$current = $this->getHead();

		while ( $current != NULL )
		{
			$current->printVal();

			$current = $current->getNext();
		}
	}

	private $tail = NULL;
	private $head = NULL;



}


$ll = new linkedList();

$ll->push(112);
$ll->enqueue(5);
$ll->enqueue(7);
$ll->enqueue(9);
$ll->push(11);
$ll->printList();
$ll->push(12);
$ll->enqueue(3);
$ll->enqueue(9);

$ll->printList();

?>
