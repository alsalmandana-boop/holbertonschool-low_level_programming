# Green Efficiency Analysis #

# Measurement Methodology

In this project, I measured and compared the performance of two different algorithms using the same input data and the same execution environment. The execution time was measured using the `clock()` function from the C standard library.

To make the comparison fair and improve the accuracy of the results, each algorithm was executed **three times**. After that, I calculated the average execution time instead of depending on a single run. Repeating the benchmark helped reduce small timing differences between executions and provided more reliable results.

I also used instrumentation to measure the execution time of each stage of the program. Instead of measuring only the total runtime, I recorded the time spent in the Build Data, Process, and Reduce stages. This helped me understand which part of the program consumed the most execution time.

The recorded execution times for the instrumented program were:

- Total execution time: **0.001153 seconds**
- Build Data: **0.000487 seconds**
- Process: **0.000481 seconds**
- Reduce: **0.000180 seconds**

---

## Observed Performance Differences

The benchmark results showed a significant difference between the two algorithms. Based on the average of three executions, the naive algorithm had an average execution time of **2.785729 seconds**, while the single-pass algorithm completed in only **0.000106333 seconds**.

This means that the single-pass algorithm was approximately **26,198 times faster** than the naive algorithm. The main reason for this difference is that the naive algorithm performs repeated operations while the single-pass algorithm processes the data only once. As the input size increases, the performance difference becomes much larger.

The instrumentation results also showed that most of the execution time was spent in the Build Data and Process stages, while the Reduce stage required much less time. This information is useful because it helps identify which stages should be optimized first.

---

### Relation Between Runtime and Energy Consumption

Execution time and energy consumption are closely related. A program that finishes its work faster usually requires the processor to work for a shorter period of time. Because of this, faster algorithms often consume less energy, especially when processing large amounts of data or when executed many times.

Although this project did not directly measure power consumption, the execution time provides a good indication of efficiency. Since the single-pass algorithm completed the task much faster than the naive algorithm, it is expected to use less processing time and potentially consume less energy.

---

##### Limitations of the Experiment

This experiment has a few limitations. The execution time may change slightly between runs because of background processes running on the operating system. In addition, the benchmark was performed on a single machine using one dataset, so the results may be different on another system or with different input sizes.

Another limitation is that energy consumption was not measured directly. The conclusions about energy efficiency were based only on the execution time of the algorithms.

---

###### Practical Engineering Takeaway

This project showed me that choosing an efficient algorithm can make a huge difference in performance. Even when two algorithms produce the same output, their execution time can be very different.

I also learned the importance of benchmarking correctly by using the same test conditions, repeating the benchmark multiple times, and calculating the average execution time. Instrumentation helped me understand where the program spent most of its execution time, making it easier to identify performance bottlenecks.

Overall, this project demonstrated that improving algorithm efficiency can significantly reduce execution time, improve overall performance, and potentially reduce energy consumption.