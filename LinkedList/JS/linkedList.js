function Node()
{
	var value = 0;
	nextNode = null;

}

let linkedList = {

	head : null,
	tail : null,
	length: 0,

	init: function(val){
		var tmp = new Node();
		tmp.value = val;
		tmp.nextNode = null;

		this.head = tmp;

		this.length++;
	},

//Add node to front of list
	enqueue : function(val){
		let tmp = new Node();
		tmp.value = val;
		tmp.nextNode = this.head;
	
		this.head = tmp;
	},

//print the list	
	display : function() {
		let current = this.head;

		while(current != null){
			console.log(current.value);
			current = current.nextNode;
		}
	},

//removes and return the first node
	dequeue : function(){
		let tmp = new Node();
		tmp.value = null;
		tmp.nextNode = null;

		tmp = this.head;

		this.head = this.head.nextNode;

		return tmp;
	},

//append to list
	push : function(value){
		let tmp = new Node();
		tmp.nextNode = null;
		tmp.value = value;

		if (this.head == null){
			this.head = tmp;
		}
		else{	
			let current = this.head;

			while(current.nextNode != null){
				current = current.nextNode;
			}
		current.nextNode = tmp; 
		}
		
		this.length++;
	},

//build random linked list w/ push
//TO DO:  Init the list with a random variable rather than having to init it first and then run this method
	initRandPB : function(numOfItems, numLimit)
	{
		for (var i = 0; i < numOfItems; i++)
		{
			let num = Math.floor(Math.random() * numLimit);
			this.push(num);
			console.log(num);
		}

	},

	initIncreaseList : function (numOfItems){
		for (var i = 0; i < numOfItems; i++){
			this.push(i);
		}
	},

//Return the middle node
	getMiddle: function()
	{
		if (this.head == null){
			return this;
		}
		let fastptr = this.head.nextNode;
		let slowptr = this.head;
		
		while (fastptr != null)
		{
			fastptr = fastptr.nextNode;
			if(fastptr != null)
			{
				slowptr = slowptr.nextNode;
				fastptr = fastptr.nextNode;
			}
		}

		return slowptr;
	},

/*
 * ONLY WORKS FOR EVEN LINKEDLISTS
	getMiddle : function(){
		let fast = this.head;
		let slow = this.head;

		while(fast.nextNode.nextNode != null)
		{
			fast = fast.nextNode.nextNode;
			slow = slow.nextNode;
		}

		return slow;


	},
*/

//Split the list in half and return the second half
	splitMiddle : function(){
		if(this.head == null){
			return this;
		}
		let fastptr = this.head.nextNode;
		let slowptr = this.head;
		let halfList = new Node();
		halfList.value = null;
		halfList.nextNode=null;

		while (fastptr != null)
		{
			fastptr = fastptr.nextNode;
			if(fastptr != null)
			{
				slowptr = slowptr.nextNode;
				fastptr = fastptr.nextNode;
			}
		}
			halfList = slowptr.nextNode;
			slowptr.nextNode = null;
	
		return halfList;
	},

	shuffleList : function()
	{
		if (this.head == null){
			return this;
		}
		let fastptr = this.head.nextNode;
		let slowptr = this.head;
		
		while (fastptr != null)
		{
			fastptr = fastptr.nextNode;
			if(fastptr != null)
			{
				slowptr = slowptr.nextNode;
				fastptr = fastptr.nextNode;
			}
		}

		let first = this.head;
		let second = slowptr.nextNode;
		let next = null;
//1
		next = first.nextNode;
		first.nextNode = second;
		first = next;
//2		
		next = second.nextNode;
		second.nextNode = first;
		second = next;
//3
		next = first.nextNode;
		first.nextNode = second;
		first = next;
//4
		next = second.nextNode;
		second.nextNode = first;
		second = next;
//5
		next = first.nextNode;
		first.nextNode = second;
		first = next;
//6

	}

}


let ll = Object.create(linkedList);
let bs = Object.create(linkedList);
ll.initIncreaseList(6);
//ll.display();

ll.shuffleList();
console.log(ll.head.value);
console.log(ll.head.nextNode.value);
console.log(ll.head.nextNode.nextNode.value);
console.log(ll.head.nextNode.nextNode.nextNode.value);
console.log(ll.head.nextNode.nextNode.nextNode.nextNode.value);
console.log(ll.head.nextNode.nextNode.nextNode.nextNode.nextNode.value);

