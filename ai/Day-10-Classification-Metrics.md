
## 🔹 Confusion Matrix Basics

For binary classification:

- **TP (True Positive):** model predicts positive and it is actually positive.  
- **TN (True Negative):** model predicts negative and it is actually negative.  
- **FP (False Positive):** model predicts positive but it is actually negative.  
- **FN (False Negative):** model predicts negative but it is actually positive.

All metrics below are computed from TP, TN, FP, FN.

---

## 🔹 Accuracy

- **Definition:** proportion of all correct predictions.

\[
\text{Accuracy} = \frac{TP + TN}{TP + TN + FP + FN}
\]

- Good when classes are **balanced** and all mistakes are equally costly.[web:145]  
- Misleading on highly **imbalanced datasets** (for example, 99 % negatives, model predicts everything negative → 99 % accuracy, but useless).

---

## 🔹 Precision and Recall

- **Precision (Positive Predictive Value):**

\[
\text{Precision} = \frac{TP}{TP + FP}
\]

  - Out of all predicted positives, how many are actually positive.
  - High precision → few false positives.

- **Recall (Sensitivity / True Positive Rate):**

\[
\text{Recall} = \frac{TP}{TP + FN}
\]

  - Out of all actual positives, how many were detected by the model.
  - High recall → few false negatives.

**Examples**

- Spam detection: often care more about **precision** (do not mark legit emails as spam).  
- Disease screening: often care more about **recall** (do not miss sick patients).

---

## 🔹 F1 Score

- **Definition:** harmonic mean of precision and recall.

\[
\text{F1} = 2 \cdot \frac{\text{Precision} \cdot \text{Recall}}{\text{Precision} + \text{Recall}}
\]

- Balances precision and recall into a single number; useful when classes are imbalanced or when both types of errors matter.
- Low if either precision or recall is low; forces the model to be good at **both**.

---

## 🔹 AI – Day 10 Takeaways

- Use **accuracy** only when classes are balanced; otherwise look at **precision, recall, and F1**.[web:145][web:148]  
- Metric choice must match the business goal: spam filters, fraud detection, and medical tasks usually report precision, recall, and F1 instead of accuracy alone.
