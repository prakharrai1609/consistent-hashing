**Consistent Hashing**

1. **Motivation**:
   - In distributed systems, data is often partitioned and distributed across multiple nodes.
   - Nodes can be added or removed over time, which poses a challenge: how to reassign data while minimizing disruption.

2. **Key Idea**:
   - Consistent hashing is a technique that solves this problem efficiently.
   - It maps data keys and node addresses to a common ring.

3. **Data Distribution**:
   - Each node and data key is hashed to a position on the ring.
   - The consistent hashing algorithm ensures that each key is assigned to the nearest node on the ring.

4. **Virtual Nodes** (Example in the Code):
   - To evenly distribute data, each physical node is represented by multiple virtual nodes on the ring.
   - Virtual nodes are positioned around the ring, giving the appearance of more nodes.

5. **Adding Nodes** (Example in the Code):
   - When a new node is added, its virtual nodes are placed on the ring.
   - Data keys are reassigned to the nearest virtual node, causing minimal disruption.

6. **Removing Nodes** (Example in the Code):
   - When a node is removed, its virtual nodes are removed from the ring.
   - Data keys previously assigned to those nodes are reassigned to the next nearest node, again minimizing disruption.

7. **Example in the Code**:
   - The code demonstrates consistent hashing with 3 virtual nodes per real node.
   - `addNode` adds nodes to the ring with virtual nodes.
   - `removeNode` removes nodes and reassigns data.
   - `getNode` finds the responsible node for a given data key.

8. **Benefits**:
   - Consistent hashing reduces data movement when nodes are added or removed, making it efficient for distributed systems.
   - It ensures that most data remains with the same node, leading to predictable and efficient data retrieval.

9. **Use Cases**:
   - Consistent hashing is widely used in distributed databases, caching systems, and load balancers to distribute data and traffic effectively.

In summary, consistent hashing is a fundamental technique in distributed systems that allows efficient data distribution and minimal disruption when nodes are added or removed. It provides a robust solution for addressing the challenges of data distribution in a distributed environment.

<hr>

## The three server problem:

<hr>

**Scenario**: You have a distributed caching system with three cache servers (A, B, and C) that store cached data, and you want to decide which server to use for caching or retrieving data based on the data's key.

**Step 1: Initialization**
1. We start with a consistent hashing ring, and each server (A, B, C) is represented multiple times on this ring. These representations are called virtual nodes. For simplicity, let's use just one virtual node per server.

   - Server A is represented as `A-1`.
   - Server B is represented as `B-1`.
   - Server C is represented as `C-1`.

   Imagine these virtual nodes placed evenly around the ring.

**Step 2: Data Placement**
2. You want to cache a piece of data with a key "mydata." To determine which server should store this data, you hash the key "mydata" (using a consistent hash function) and find its position on the ring.

   - The hash of "mydata" corresponds to a position between `B-1` and `C-1`.

3. The caching system decides that `C-1` is the responsible server for "mydata" because it's the next virtual node in the clockwise direction from the data's hash position.

**Step 3: Data Retrieval**
4. When you want to retrieve "mydata," you recompute its hash and find its position on the ring.

   - The hash of "mydata" again corresponds to a position between `B-1` and `C-1`.

5. The caching system checks the ring and quickly determines that `C-1` is still responsible for "mydata."

**Step 4: Node Removal**
6. If you decide to add or remove a server (e.g., adding `D-1`), consistent hashing minimizes data movement. `D-1` is placed on the ring, and some of the data (for example, "mydata") might get reassigned to `D-1`.

**Step 5: Load Balancing**
7. If server A starts getting too much traffic, you can add more virtual nodes for A (e.g., `A-2`, `A-3`) to the ring. This way, data will start balancing between the physical nodes (A, B, C) more evenly.

In summary, consistent hashing is used to distribute and access data efficiently across multiple servers while handling server additions or removals with minimal disruption. It ensures that data is consistently stored and retrieved from the appropriate server based on the data's key.
