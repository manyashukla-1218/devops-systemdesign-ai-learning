 ## 🔹 Why Do We Split the Data?

- A model can memorize the training data; to check real performance, we must test it on **unseen data**. 
- Splitting data into **train, validation, and test** sets helps with:
  - Fitting the model.  
  - Tuning hyperparameters and choosing models.  
  - Estimating final, unbiased performance.

---

## 🔹 Train, Validation, and Test Sets

- **Training set:** used to fit model parameters (weights).  
- **Validation set:** used to compare models and tune hyperparameters (for example, depth of tree, regularization strength).  
- **Test set:** held‑out set used only at the end to estimate generalization performance once all decisions are fixed.

Typical split examples:

- 70 % train / 15 % validation / 15 % test.  
- 80 % train / 10 % validation / 10 % test (small datasets).

Important: splits should be **random and representative**; never let time or ordering accidentally separate classes or distributions.

---

## 🔹 k‑Fold Cross‑Validation (CV)

- In **k‑fold CV**, the training data is split into *k* folds (for example, 5). 
- Process:
  1. Reserve test set and do **not** touch it.  
  2. On the remaining data, create *k* folds.  
  3. For each fold:
     - Train on *k−1* folds.  
     - Validate on the remaining fold.  
  4. Average validation scores over all *k* runs.

Benefits:

- More reliable evaluation than a single validation split, especially on small datasets.  
- Helps compare models and hyperparameters more robustly.

---

## 🔹 Correct Workflow for Model Selection

High‑level steps:

1. Shuffle and split data into **train+val** and **test**.
2. On the train+val portion:
   - Use cross‑validation or train/validation split to tune hyperparameters and select the best model.  
3. Once a model is chosen, **retrain** it on the combined train+validation data.  
4. Finally, evaluate once on the **test set** to report metrics (accuracy, precision/recall/F1, etc.).

The test set is only used at the very end to avoid leaking information and over‑optimistic metrics.

---

## 🔹 AI – Day 11 Takeaways

- Always separate data for **training**, **model selection (validation/CV)**, and **final evaluation (test)**.
- Use k‑fold cross‑validation on the training portion to pick models and hyperparameters, then report metrics on the untouched test set.
