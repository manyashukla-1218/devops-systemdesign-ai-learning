## 🔹 Why Focus on These Two?
 
- Linear regression aur logistic regression dono ML ke sabse basic aur most-used algorithms hain.
- Interviews me frequently pucha jata hai: “difference between linear and logistic regression” + “when to use which”.
---

## 🔹 Linear Regression – Predicting Continuous Values

- **Problem type:** Regression – output is a **continuous number** (price, score, time, demand).  
- **Idea:** Model assumes a linear relationship between input features and output.

### 1. Model Form

- Prediction \( \hat{y} \) is a weighted sum of inputs plus bias:  

  \[
  \hat{y} = w_0 + w_1 x_1 + w_2 x_2 + \dots + w_n x_n
  \]

- Weights \( w_i \) represent how much each feature affects the output.

### 2. Training

- Uses **Least Squares / Ordinary Least Squares (OLS)** to find weights that minimize **Mean Squared Error (MSE)** between predictions and true values.
- Assumptions (high level): relationship roughly linear, errors with constant variance, and errors not extremely correlated.

### 3. Example

- Predict **house price** from area, number of rooms, and location score.  
- Output could be any real value (for example, 53.2 lakh), so regression is appropriate.

---

## 🔹 Logistic Regression – Predicting Probabilities / Classes

- **Problem type:** Classification – output is a **category**, usually binary (0/1) like spam / not‑spam.
- **Idea:** First compute linear combination, then pass through **sigmoid** to get probability.

### 1. Model Form

- First compute:  

  \[
  z = w_0 + w_1 x_1 + \dots + w_n x_n
  \]

- Then convert to probability using **sigmoid** function:  

  \[
  \hat{p} = \frac{1}{1 + e^{-z}}
  \]

- \(\hat{p}\) = probability of class 1 (for example, spam).

### 2. Training

- Uses **Maximum Likelihood Estimation (MLE)** rather than OLS.
- Loss function = **log loss / cross‑entropy**, jo high penalty deta hai wrong confident predictions ke liye.

### 3. Decision Boundary

- Final class decide karne ke liye threshold use hoti hai (commonly 0.5):  
  - \(\hat{p} \ge 0.5\) → class 1  
  - \(\hat{p} < 0.5\) → class 0  
- Because of sigmoid, output always between 0 and 1, so logistic regression probabilities naturally interpret ho sakte hain.

---

## 🔹 Key Differences – Linear vs Logistic Regression

- **Problem type**[web:81][web:82][web:86]  
  - Linear regression → regression tasks, continuous output.  
  - Logistic regression → classification tasks, categorical output.

- **Output**  
  - Linear → directly numeric \( \hat{y} \in (-\infty, \infty) \).  
  - Logistic → probability \( \hat{p} \in [0,1] \) via sigmoid, then threshold to get class.

- **Training objective**  
  - Linear → minimize **MSE** using OLS.  
  - Logistic → maximize likelihood / minimize **log loss**.

- **Assumptions**  
  - Linear → assumes linear relationship and homoscedastic errors (roughly constant variance). 
  - Logistic → assumes log‑odds of outcome are linear in features; no constant‑variance requirement.

---

## 🔹 When to Use Which?

- If **target is continuous number** → start with linear regression (for example, price, time, demand). 
- If **target is class / label** → use logistic regression (for example, spam, churn, fraud, disease yes/no).
- Rule of thumb:  
  - “Can output be safely anything between minus infinity and plus infinity?” → linear.  
  - “Should output be probability / category?” → logistic.

---

## 🔹 Interview Questions

1. What is the main difference between linear and logistic regression in terms of problem type and output?  
2. Why can’t we use linear regression directly for classification problems?  
3. What loss functions are commonly used in linear regression and logistic regression?

---

## ✅ What I Learned Today

- Linear regression predicts continuous values using a straight‑Below teenon subjects ka **Day 06** content diya hai, har ek ko direct `.md` file ki tarah GitHub me push kar sakti ho.

---

## 1) AI – Linear vs Logistic Regression


## 🔹 Why Study These Two Algorithms?

* Linear regression and logistic regression are two of the most widely used classical ML algorithms and appear frequently in interviews.
* Dono algorithms same idea (input features → weighted sum) use karte hain, lekin target variable aur output interpretation completely different hota hai.

***

## 🔹 Linear Regression – Predicting Continuous Values

* **Goal:** Predict a **continuous** numeric value from input features (for example, price, demand, response time).
* **Model idea:**  
  * Model a straight‑line relationship between inputs and output:
    * \( y \approx w_0 + w_1 x_1 + \dots + w_n x_n \)  (concept only).  
  * Learns weights \(w_i\) that minimize the **sum of squared errors** (Ordinary Least Squares).

* **Assumptions (intuitively):**[5][4]
  * Relationship is roughly linear.  
  * Errors have constant variance (homoscedasticity) and are independent.  
  * Extreme outliers can hurt the line badly.

* **Examples:**
  * Predict house price from area, rooms, locality.  
  * Predict server latency from traffic and CPU usage.

***

## 🔹 Logistic Regression – Predicting Probabilities for Classes

* **Goal:** Predict probability of a **categorical** outcome (mostly binary like spam/not‑spam, churn/no‑churn).
* **Model idea:**
  * Still computes a weighted sum \( z = w_0 + w_1 x_1 + \dots + w_n x_n \) but then passes it through a **sigmoid** function to squash it between 0 and 1.
  * Output is \( p = \sigma(z) \) ≈ probability of “class 1”; if \(p > 0.5\) then label = 1, else 0.

* **Training:**  
  * Uses **Maximum Likelihood Estimation (MLE)** instead of least squares to find weights.
  * Loss function usually cross‑entropy.

* **Examples:**
  * Will this transaction be fraudulent (yes/no)?  
  * Will the user click this ad?  
  * Is this email spam?

***

## 🔹 Key Differences – Linear vs Logistic Regression

* **Type of problem**
  * Linear → regression problems (continuous output).  
  * Logistic → classification problems (categorical output).

* **Output**
  * Linear → direct numeric value (can be any real number).  
  * Logistic → probability between 0 and 1, then threshold to decide class.

* **Loss / training**
  * Linear → Ordinary Least Squares, minimizes squared error.
  * Logistic → Maximum Likelihood with cross‑entropy loss.

* **Assumptions**
  * Linear → assumes linear relationship and constant variance of errors.
  * Logistic → assumes relation between inputs and **log‑odds** of outcome; no homoscedasticity requirement.

* **When to use**
  * Use linear regression when target is real‑valued (price, temperature, time).  
  * Use logistic regression when target is class label or probability of an event (spam/not‑spam, purchased/not‑purchased).

***

## 🔹 Interview Questions

* What is the main difference between linear regression and logistic regression?  
* Why can’t we simply use linear regression for a classification problem?  
* What does the sigmoid function do in logistic regression?

***

## ✅ What I Learned Today

* Linear regression models continuous targets with a straight‑line relationship and uses least squares, whereas logistic regression models class probabilities via a sigmoid and uses maximum likelihood.
* Choosing between them depends primarily on whether the target variable is **continuous** or **categorical**, which is a common interview discussion.
