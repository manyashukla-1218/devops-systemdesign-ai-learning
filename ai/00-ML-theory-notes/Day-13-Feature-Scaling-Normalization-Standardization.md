## 🔹 Why Feature Scaling?

- Many ML algorithms are sensitive to the **scale** of features; large‑magnitude features can dominate distance or gradient calculations. 
- Scaling helps:
  - Speed up training and improve convergence.  
  - Ensure all features contribute more equally to the model.

Algorithms that especially benefit: k‑NN, k‑Means, SVMs, gradient‑based models, neural networks.

---

## 🔹 Min–Max Normalization (0–1 Scaling)

- **Idea:** rescale each feature to a fixed range, typically \([0, 1]\).

\[
x_{\text{norm}} = \frac{x - x_{\min}}{x_{\max} - x_{\min}}
\]

- After scaling, minimum value becomes 0 and maximum becomes 1.[web:175][web:178]  
- Works well when:
  - Feature has known min/max.  
  - No heavy extreme outliers (they can squash the rest of the data).

Used often in neural networks (especially with sigmoid/tanh) and image pixel scaling.

---

## 🔹 Standardization (Z‑Score Scaling)

- **Idea:** center features at zero mean and scale to unit variance.

\[
x_{\text{std}} = \frac{x - \mu}{\sigma}
\]

- Resulting feature has mean ≈ 0 and standard deviation ≈ 1.
- Useful when:
  - Data is roughly Gaussian.  
  - Algorithms assume or benefit from standardized inputs (linear/logistic regression, many neural nets).

Compared to min–max, standardization is more robust when there are outliers because it does not clamp values to a fixed range.

---

## 🔹 Practical Notes

- Always **fit scaling parameters on training data only** (compute min/max or mean/std on train) and apply the same transformation to validation/test data.  
- Categorical features typically should not be scaled; apply scaling after encoding numeric features.

---

## 🔹 AI – Day 13 Takeaways

- Feature scaling is essential for distance‑based and gradient‑based models; min–max normalization puts features into \([0,1]\), while standardization sets mean 0, variance 1. 
- Fit scaling on the training set and reuse those parameters on validation/test to avoid data leakage.
