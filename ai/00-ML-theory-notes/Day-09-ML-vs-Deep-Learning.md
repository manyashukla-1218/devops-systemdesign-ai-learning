## 🔹 Classical ML vs Deep Learning – Big Picture

- **Machine Learning (ML)** is a broad field where models learn patterns from data using algorithms like linear regression, trees, SVMs, etc.
- **Deep Learning (DL)** is a subset of ML that uses deep neural networks with many layers to automatically learn features from data.

---

  ## 🔹 Data & Feature Engineering

- Classical ML usually works best on **structured / tabular data** (rows & columns) and relies heavily on **feature engineering** by humans. 
- Deep Learning shines on **unstructured data** like images, audio, and text, because neural networks can learn complex features directly from raw inputs.

---

## 🔹 Model Complexity & Resources

- ML models are typically **smaller and faster to train**, and run well on CPUs with modest hardware. 
- DL models (CNNs, RNNs, Transformers) have **many parameters**, usually need large labeled datasets and GPUs/TPUs for efficient training.

---

## 🔹 Interpretability & Use Cases

- Classical ML (for example, tree‑based models, linear models) is often **easier to interpret** – feature importance, coefficients, etc. can be inspected. 
- Deep Learning is more of a **black box**, but often gives better accuracy for vision, speech, and NLP tasks.

**Typical choices**

- Use ML for: credit scoring, churn prediction, tabular business data, small/medium datasets.  
- Use DL for: image classification, object detection, speech recognition, translation, large‑scale text tasks.

---

## 🔹 AI – Day 09 Takeaways

- Deep Learning ⊂ Machine Learning: choose the **simplest model** that meets performance needs, especially when data or compute is limited.  
- Start with classical ML for structured data; move to DL when dealing with unstructured data or when simpler models hit a performance ceiling.
