# Day 08 – Supervised vs Unsupervised Learning

---

 ## 🔹 What Is Supervised Learning?

- In **supervised learning**, the training data has both **inputs (features)** and **correct outputs (labels)**, so the model learns a mapping from inputs to      labels.
- Typical goal: predict labels for new, unseen inputs as accurately as possible.

**Examples of supervised problems**

- Predicting house **price** from its features (regression).  
- Classifying an email as **spam / not spam** (classification).  
- Predicting whether a customer will **churn / not churn**.

**Main types**

- **Regression:** target is continuous (price, time, rating).  
- **Classification:** target is discrete class (spam/ham, cat/dog, disease/no‑disease).

**Common supervised algorithms**

- Linear Regression, Logistic Regression.  
- Decision Trees, Random Forests, Gradient Boosting.  
- Support Vector Machines (SVM), k‑Nearest Neighbours (k‑NN).

---

## 🔹 What Is Unsupervised Learning?

- In **unsupervised learning**, training data has **inputs only**, no labels; the algorithm tries to discover structure or patterns in the data on its own. 
- Goal: group similar items, detect structure, or compress data rather than predict labeled outputs.

**Examples of unsupervised problems**

- Customer **segmentation** based on behavior (grouping customers into clusters).  
- Grouping similar documents or news articles.  
- Detecting unusual patterns in logs (anomaly detection style).

**Common unsupervised algorithms**

- Clustering: k‑Means, Hierarchical clustering, DBSCAN.  
- Dimensionality reduction: PCA, t‑SNE, autoencoders (bridge to deep learning).

---

## 🔹 Key Differences (Supervised vs Unsupervised)

- **Labels**  
  - Supervised: dataset has labeled examples (input, correct output).  
  - Unsupervised: dataset has only inputs; no correct outputs given.

- **Goal**  
  - Supervised: learn to **predict** labels for new data (regression or classification).
  - Unsupervised: **discover structure** in data (clusters, latent factors, anomalies).

- **Evaluation**  
  - Supervised: accuracy, F1, RMSE, etc. using known labels.
  - Unsupervised: harder—often based on internal metrics (cluster separation) or downstream usefulness.

---

## 🔹 AI – Day 08 Takeaways

- Supervised learning uses labeled data and is mainly about **prediction** (classification & regression), while unsupervised learning uses unlabeled data and is mainly about **pattern discovery**. 
- Many real systems combine both: supervised models trained on features that were discovered or engineered by unsupervised methods.
