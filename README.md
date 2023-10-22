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
