from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
os.environ['TF_CPP_MIN_LOG_LEVEL']='2'
import tensorflow as tf

import argparse
import sys

from input_data import input_data

FLAGS = None


def main(_):
  # Create the model
  x = tf.placeholder(tf.float32, [None, 1000])
  W = tf.Variable(tf.zeros([1000, 250]))
  b = tf.Variable(tf.zeros([250]))
  y = tf.matmul(x, W) + b

  # Define loss and optimizer
  y_ = tf.placeholder(tf.float32, [None, 250])

  cross_entropy = tf.reduce_mean(
    tf.nn.softmax_cross_entropy_with_logits(labels=y_, logits=y))
  train_step = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy)

  sess = tf.InteractiveSession()
  tf.global_variables_initializer().run()

  # Train
  for _ in range(180):
    batch_xs, batch_ys = input_data.train_next_batch(100)
    sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys})

  # Test trained model
  correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1))
  accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
  test_xs, test_ys = input_data.test_next_batch(input_data.TEST_DB_SIZE)
  print(sess.run(accuracy, feed_dict={x: test_xs,
                                      y_: test_ys}))

if __name__ == '__main__':
  tf.app.run(main=main)