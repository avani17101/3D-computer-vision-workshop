import numpy as np
import time
import icp
# Constants
N = 10000                                    # number of random points in the dataset
num_tests = 10                            # number of test iterations
dim = 3                                   # number of dimensions of the points
noise_sigma = .01                           # standard deviation error to be added
translation = 1                            # max translation of the test set
rotation = .7                               # max rotation (radians) of the test set

def rotation_matrix(axis, theta):
    axis = axis/np.sqrt(np.dot(axis, axis))
    a = np.cos(theta/2.)
    b, c, d = -axis*np.sin(theta/2.)

    return np.array([[a*a+b*b-c*c-d*d, 2*(b*c-a*d), 2*(b*d+a*c)],
                  [2*(b*c+a*d), a*a+c*c-b*b-d*d, 2*(c*d-a*b)],
                  [2*(b*d-a*c), 2*(c*d+a*b), a*a+d*d-b*b-c*c]])

def test_icp():
    A = np.random.rand(N, dim)
    total_time = 0
    for i in range(num_tests):

        B = np.copy(A)

        #Applying Random transformation

        # Translate
        t = np.random.rand(dim)*translation
        B += t

        # Rotate
        R = rotation_matrix(np.random.rand(dim), np.random.rand()*rotation)
        B = np.dot(R, B.T).T

        # Add noise
        B += np.random.randn(N, dim) * noise_sigma

        # Shuffle to disrupt correspondence
        np.random.shuffle(B)

        # Run ICP
        start = time.time()
        T,_,_ = icp.icp(B, A, tolerance=0.000001)
        total_time += time.time() - start

        # Make C a homogeneous representation of B
        C = np.ones((N, 4))
        C[:,0:3] = B

        # Transform C
        C = np.dot(T, C.T).T

    print('icp fit time: {:.3}'.format(total_time/num_tests))
test_icp()
