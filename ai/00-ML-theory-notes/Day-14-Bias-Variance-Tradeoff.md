## 🔹 Bias and Variance – Intuition

- **Bias** measures how far the model’s average predictions are from the true function; high bias models are too simple and tend to **underfit**.  
- **Variance** measures how much the model’s predictions change when the training data changes; high variance models are too complex and tend to **overfit**.

Total error (conceptually):

\[
\text{Total Error} \approx \text{Bias}^2 + \text{Variance} + \text{Irreducible Error}
\]

---

## 🔹 Underfitting vs Overfitting

- **Underfitting (high bias, low variance):**  
  - Model is too simple; performs poorly on both training and test data.  
  - Example: trying to fit a complex curve with a straight line.

- **Overfitting (low bias, high variance):**  
  - Model matches training data very closely but generalizes poorly to new data.  
  - Example: very deep tree memorizing noise.

Goal: find a **sweet spot** where bias and variance are balanced, giving lowest error on unseen data.

---

## 🔹 How to Control Bias vs Variance

Ways to reduce **bias** (when model is too simple):

- Use a more flexible model (for example, from linear to polynomial or tree‑based).
- Add more relevant features or use non‑linear feature transformations.

Ways to reduce **variance** (when model is too complex):

- Regularization (L1/L2), pruning trees, limiting model depth. 
- Use more training data or apply ensembling techniques like bagging/Random Forests.

Changing model complexity usually decreases one (bias) while increasing the other (variance); this tradeoff must be tuned by validation/CV.

---

## 🔹 AI – Day 14 Takeaways

- High bias → underfitting; high variance → overfitting; real‑world models must **balance** the two for best generalization.
- Model choice, regularization strength, and feature engineering are key levers for managing the bias–variance tradeoff.
