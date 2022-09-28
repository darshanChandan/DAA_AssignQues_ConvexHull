# Convex Hull and sum inside polygon

### Darshan Chandan <br/> A-38 <br/> DAA Assignment

#### Problem Statement : Implement a solution for finding a summation of elements from a matrix. <br/>  &nbsp;&nbsp;&nbsp;&nbsp; &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Example: Accept a 2D matrix dimension. Populate using random number [non-zero]
<br/>
Accept any five dimension values from the user for example [1,1] [4,10] 10,7] [15,3] [20,18].<br/>Check the region covered by these points in the matrix.<br/>Calculate the boundary by either considering all points or ignoring few points which may not come on boundary [convex hull].<br/> Find sum of elements in the region.<br/>

## Solution:

#### Steps-
1) First we made a matrix (in this example it is of size 10x10) and populated it with random numbers using rand() function.
2) Then take 5 points from the user.
3) then check for each point if it lies inside Convex Hull by using ConvexHull function.
4) If point lies inside Convex Hull then add the value on that point from matrix into our answer.

![daa_img_5](https://user-images.githubusercontent.com/114525881/192862436-00fe43a5-4661-4679-be42-cc391dba3861.jpeg)
![daa_img_6](https://user-images.githubusercontent.com/114525881/192862472-e83e3634-6d23-4c3a-b3d5-93707dab0dd9.jpeg)
![daa_img_7](https://user-images.githubusercontent.com/114525881/192862489-f5cdc37c-49be-4dff-8c22-9a140a650f3e.jpeg)
![daa_img_8](https://user-images.githubusercontent.com/114525881/192862497-6fd02a7a-43ac-4779-941e-ff3cd1b96bf8.jpeg)
![daa_img_9](https://user-images.githubusercontent.com/114525881/192862504-8486c6a0-ec07-44b9-85ef-70356c09bf6e.jpeg)
![daa_img_10](https://user-images.githubusercontent.com/114525881/192862516-fca03d84-a2fd-4633-924f-9d3ac6a3ec92.jpeg)
