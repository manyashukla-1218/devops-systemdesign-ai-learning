## 🔹 What Is Overfitting?

- A model **overfits** when it learns noise and random fluctuations in the training data instead of the underlying pattern.
- Symptoms:
  - Very low training error but high validation/test error.  
  - Model is too complex for the amount of data available.

---
## 🔹 Idea of Regularization

- **Regularization** adds a **penalty term** to the loss function to discourage large parameter values and overly complex models.
- Goal: keep the model simpler, improve generalization, and reduce overfitting without completely changing the model class.

Generic form:

\[
\text{Loss}_{\text{regularized}} = \text{Loss}_{\text{data}} + \lambda \cdot \text{Penalty(weights)}
\]

where \(\lambda\) controls the strength of regularization (bigger \(\lambda\) = stronger penalty).

---

## 🔹 L2 Regularization (Ridge)

- Adds the **sum of squared weights** to the loss:

\[
\text{Penalty}_{L2} = \sum_i w_i^2
\]

- Effect:
  - Pushes weights towards zero but rarely makes them exactly zero.
  - Produces more **smooth, stable** models and helps with multicollinearity (correlated features).

- Commonly used in linear/logistic regression, neural networks (weight decay).

---

 ## 🔹 L1 Regularization (Lasso)

- Adds the **sum of absolute weights** to the loss:

\[
\text{Penalty}_{L1} = \sum_i |w_i|
\]

- Effect:
  - Encourages many weights to become **exactly zero**, effectively performing **feature selection**.
  - Useful when expecting only a subset of features to be truly important.

- Often used when interpretability and sparsity are desired.

---

## 🔹 AI – Day 12 Takeaways

- Overfitting = model fits training data too well but generalizes poorly; regularization combats this by penalizing large weights and complexity. 
- L2 makes weights small and stable; L1 drives some weights to zero and can select features—both are standard tools in ML interviews and practice.
