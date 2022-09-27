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

![img1_daa_assign](https://user-images.githubusercontent.com/114525881/192630816-03e7ed73-59f7-43e5-ae18-bdbb7da86bf4.jpeg)

![img2_daa_assign](https://user-images.githubusercontent.com/114525881/192630838-e289778a-3b22-4c02-95f1-942d8b12ba77.jpeg)


![img3_daa_assign](https://user-images.githubusercontent.com/114525881/192630868-d3d0fb96-e2b2-4612-ae1a-45e3412cd88d.jpeg)

![img_4_daa_assgn](https://user-images.githubusercontent.com/114525881/192630885-662db8d3-0981-4f47-a261-b7596348fe66.jpeg)
