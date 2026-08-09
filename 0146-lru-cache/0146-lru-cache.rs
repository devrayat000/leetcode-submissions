use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::{Rc, Weak};

#[derive(Clone, Debug)]
struct ListNode {
    key: i32,
    val: i32,
    prev: Option<Weak<RefCell<ListNode>>>,
    next: Option<Rc<RefCell<ListNode>>>,
}

impl ListNode {
    fn new(c: (i32, i32)) -> Self {
        ListNode {
            key: c.0,
            val: c.1,
            prev: None,
            next: None,
        }
    }

    fn with_neighbors(
        c: (i32, i32),
        p: Option<Weak<RefCell<ListNode>>>,
        n: Option<Rc<RefCell<ListNode>>>,
    ) -> Self {
        ListNode {
            key: c.0,
            val: c.1,
            prev: p,
            next: n,
        }
    }
}

struct LRUCache {
    capacity: usize,
    map: HashMap<i32, Rc<RefCell<ListNode>>>,
    head: Rc<RefCell<ListNode>>,
    tail: Rc<RefCell<ListNode>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {

    fn new(capacity: i32) -> Self {
        let head = Rc::new(RefCell::new(ListNode::new((-1, -1))));
        let tail = Rc::new(RefCell::new(ListNode::new((-1, -1))));

        head.borrow_mut().next = Some(Rc::clone(&tail));
        tail.borrow_mut().prev = Some(Rc::downgrade(&head));

        LRUCache {
            capacity: capacity as usize,
            map: HashMap::new(),
            head: head,
            tail: tail,
        }
    }

    fn add_node_to_head(&mut self, c: (i32, i32)) {
        let new_node = Rc::new(RefCell::new(ListNode::new(c)));
        let old_next = self.head.borrow().next.clone().unwrap();

        new_node.borrow_mut().next = Some(Rc::clone(&old_next));
        new_node.borrow_mut().prev = Some(Rc::downgrade(&self.head));

        old_next.borrow_mut().prev = Some(Rc::downgrade(&new_node));
        self.head.borrow_mut().next = Some(Rc::clone(&new_node));

        self.map.insert(c.0, new_node);
    }

    fn delete_node(&mut self, node: &Rc<RefCell<ListNode>>) {
        let prev_node = node.borrow().prev.as_ref().unwrap().upgrade().unwrap();
        let next_node = node.borrow().next.clone().unwrap();

        prev_node.borrow_mut().next = Some(Rc::clone(&next_node));
        next_node.borrow_mut().prev = Some(Rc::downgrade(&prev_node));

        let key = node.borrow().key;
        self.map.remove(&key);
    }
    
    fn get(&mut self, key: i32) -> i32 {
        if let Some(node) = self.map.get(&key).cloned() {
            let val = node.borrow().val;

            self.delete_node(&node);
            self.add_node_to_head((key, val));

            val
        } else {
            -1
        }
    }
    
    fn put(&mut self, key: i32, value: i32) {
        if let Some(node) = self.map.get(&key).cloned() {
            self.delete_node(&node);
            self.add_node_to_head((key, value));
        } else {
            if self.map.len() >= self.capacity {
                // Evict LRU node (node right before tail)
                let lru_node = self.tail.borrow().prev.as_ref().unwrap().upgrade().unwrap();

                self.delete_node(&lru_node);
            }

            self.add_node_to_head((key, value));
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */