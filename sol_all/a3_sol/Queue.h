// Queue.h

//
// Do not make any changes to this file!
//

#pragma once

#include "Announcement.h"
#include "Queue_base.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class Queue : public Queue_base<Announcement>
{
    struct Node
    {
        Announcement data;
        Node *next;
    };

    Node *head = nullptr; // always points to the first node
    Node *tail = nullptr; // always points to the last node
    int num_nodes = 0;

    bool check_rep() const
    {
        if (head == nullptr && tail == nullptr)
        {
            return true;
        }
        else if (head == nullptr || tail == nullptr)
        {
            return false;
        }
        else
        {
            return tail->next == nullptr;
        }
    }

public:
    //
    // C++ bases classes should always have a virtual destructor to that
    // inheriting classes can have their own destructors
    //
    ~Queue()
    {
        int n = 0;
        while (size() > 0)
        {
            dequeue();
            n++;
        }
    }

    //
    // Returns the number of items currently in the queue.
    //
    // Performance: O(1)
    //
    int size() const
    {
        return num_nodes;
    }

    //
    // Add an announcement to the back of the queue.
    //
    // Performance: O(1)
    //
    void enqueue(const Announcement &item)
    {
        // cout << "Announcement::enqueue: " << item << endl;
        Node *new_node = new Node{item, nullptr};

        if (head == nullptr)
        {
            // cout << "Announcement::enqueue: queue is empty" << endl;
            head = new_node;
            tail = new_node;
        }
        else
        {
            // cout << "Announcement::enqueue: queue is not empty" << endl;
            assert(tail != nullptr);
            assert(tail->next == nullptr);
            tail->next = new_node;
            tail = new_node;
        }

        num_nodes++;

        assert(check_rep());
    }

    //
    // Return a reference to the item at the front of the queue.
    //
    // Performance: O(1)
    //
    const Announcement &front() const
    {
        if (head == nullptr)
        {
            throw runtime_error("Announcement::front: queue is empty");
        }
        return head->data;
    }

    //
    // Remove item at the front of the queue.
    //
    // Performance: O(1)
    //
    void dequeue()
    {
        if (head == nullptr)
        {
            throw runtime_error("Announcement::dequeue: is empty");
        }
        else if (head->next == nullptr)
        {
            tail = nullptr;
        }
        Node *old_head = head;
        head = head->next;
        delete old_head;
        num_nodes--;

        assert(check_rep());
    }

    //
    // Returns the number of announcements currently in the queue with the given
    // user name.
    //
    // Performance: O(n)
    //
    int count_user_announcements(const string &username) const
    {
        int count = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data.get_sender_name() == username)
            {
                count++;
            }
            curr = curr->next;
        }
        return count;
    }

    //
    // Remove all announcements in the queue with the given user name. If there
    // are no announcements with that username, then nothing happens.
    //
    // Performance: O(n)
    //
    void remove_all(const string &username)
    {
        int init_size = size();
        int remove_count = 0;
        for (int i = 0; i < init_size; i++)
        {
            if (head->data.get_sender_name() == username)
            {
                cout << "Queue::remove_all: removing " << head->data << endl;
                dequeue();
                remove_count++;
            }
            else
            {
                enqueue(front());
                dequeue();
            }
        }
        assert(check_rep());
        assert(size() == init_size - remove_count);
    }

    string to_string() const
    {
        string result = "[";
        bool first = true;
        for (Node *curr = head; curr != nullptr; curr = curr->next)
        {
            if (!first)
            {
                result += ", ";
            }
            result += curr->data.to_string();
            first = false;
        }
        result += "]";
        return result;
    }

}; // class Queue
