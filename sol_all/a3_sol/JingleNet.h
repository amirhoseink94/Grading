// JingleNet.h

#pragma once

#include "JingleNet_announcer.h"
#include "Queue.h"

// helper function for promoting announcements
Announcement promote(const Announcement &m)
{
    switch (m.get_rank())
    {
    case Rank::SNOWMAN:
        return Announcement(m.get_sender_name(), Rank::ELF1, m.get_text());
    case Rank::ELF1:
        return Announcement(m.get_sender_name(), Rank::ELF2, m.get_text());
    case Rank::ELF2:
        return Announcement(m.get_sender_name(), Rank::REINDEER, m.get_text());
    case Rank::REINDEER:
        return Announcement(m.get_sender_name(), Rank::SANTA, m.get_text());
    default: // Rank::SANTA
        return m;
    }
}

class JingleNet
{
    // one queue for each rank of announcement
    Queue snowman; // lowest rank
    Queue elf1;
    Queue elf2;
    Queue reindeer;
    Queue santa; // highest rank

public:
    void send(const Announcement &m)
    {
        switch (m.get_rank())
        {
        case Rank::SNOWMAN:
            snowman.enqueue(m);
            break;
        case Rank::ELF1:
            elf1.enqueue(m);
            break;
        case Rank::ELF2:
            elf2.enqueue(m);
            break;
        case Rank::REINDEER:
            reindeer.enqueue(m);
            break;
        case Rank::SANTA:
            santa.enqueue(m);
            break;
        }
    }

    void remove_all(const string &username)
    {
        snowman.remove_all(username);
        elf1.remove_all(username);
        elf2.remove_all(username);
        reindeer.remove_all(username);
        santa.remove_all(username);
    }

    //
    // All announcements from *username* currently in the system are removed
    // from their current queue and then enqueued in the queue one rank higher.
    // If they're already at the highest rank, then nothing happens, i.e. they
    // stay in the **santa** queue.
    //
    // When items are put into another queue, they are enqueued at the back in
    // the usual way. If multiple announcements are promoted from a queue, then
    // they are enqueued so they are in the same order as they appeared in the
    // queue they were removed from.
    //
    void promote_announcements(const string &sendername)
    {
        // promote reindeer queue
        int n = reindeer.size();
        for (int i = 0; i < n; i++)
        {
            Announcement first = reindeer.front();
            if (first.get_sender_name() == sendername)
            {
                santa.enqueue(promote(first));
                reindeer.dequeue();
            }
            else
            {
                // cout << "enqueueing " << first << " at back of reindeer queue" << endl;
                // cout << "reindeer.size() == " << reindeer.size() << endl;
                reindeer.enqueue(first);
                reindeer.dequeue();
            }
        }

        // promote elf2 queue
        n = elf2.size();
        for (int i = 0; i < n; i++)
        {
            if (elf2.front().get_sender_name() == sendername)
            {
                reindeer.enqueue(promote(elf2.front()));
                elf2.dequeue();
            }
            else
            {
                elf2.enqueue(elf2.front());
                elf2.dequeue();
            }
        }

        // promote elf1 queue
        n = elf1.size();
        for (int i = 0; i < n; i++)
        {
            if (elf1.front().get_sender_name() == sendername)
            {
                elf2.enqueue(promote(elf1.front()));
                elf1.dequeue();
            }
            else
            {
                elf1.enqueue(elf1.front());
                elf1.dequeue();
            }
        }

        // promote snowman queue
        n = snowman.size();
        for (int i = 0; i < n; i++)
        {
            if (snowman.front().get_sender_name() == sendername)
            {
                elf1.enqueue(promote(snowman.front()));
                snowman.dequeue();
            }
            else
            {
                snowman.enqueue(snowman.front());
                snowman.dequeue();
            }
        }
    }

    // Announce the next announcement.
    void annnounce_next()
    {
        if (santa.size() > 0)
        {
            // cout << santa.front() << endl;
            jnet.announce(santa.front());
            santa.dequeue();
        }
        else if (reindeer.size() > 0)
        {
            jnet.announce(reindeer.front());
            reindeer.dequeue();
        }
        else if (elf2.size() > 0)
        {
            jnet.announce(elf2.front());
            elf2.dequeue();
        }
        else if (elf1.size() > 0)
        {
            jnet.announce(elf1.front());
            elf1.dequeue();
        }
        else if (snowman.size() > 0)
        {
            jnet.announce(snowman.front());
            snowman.dequeue();
        }
    }

    void announce(int n)
    {
        for (int i = 0; i < n; i++)
        {
            annnounce_next();
        }
    }

    int snowman_size() const
    {
        return snowman.size();
    }

    int elf1_size() const
    {
        return elf1.size();
    }

    int elf2_size() const
    {
        return elf2.size();
    }

    int reindeer_size() const
    {
        return reindeer.size();
    }

    int santa_size() const
    {
        return santa.size();
    }

    string to_string() const
    {
        string result = "(left is front of queue, right is back of queue)\n";
        result += "   santa: " + std::to_string(santa_size()) + " " + santa.to_string() + "\n";
        result += "reindeer: " + std::to_string(reindeer_size()) + " " + reindeer.to_string() + "\n";
        result += "    elf2: " + std::to_string(elf2_size()) + " " + elf2.to_string() + "\n";
        result += "    elf1: " + std::to_string(elf1_size()) + " " + elf1.to_string() + "\n";
        result += " snowman: " + std::to_string(snowman_size()) + " " + snowman.to_string() + "\n";
        return result;
    }

}; // class JingleNet
