 ## 🔹 Why Neural Networks?

- Neural networks deep learning ka core building block hain, jo images, text, speech jaise complex data ko handle kar sakte hain.  
- Interviews me high‑level understanding (layers, weights, activation functions, training loop) expect ki jaati hai, chahe detailed math na bhi aata ho.

---

## 🔹 Basic Architecture

- Ek typical feed‑forward neural network 3 main parts se banta hai: 
  - **Input layer:** raw features receive karta hai (pixels, numerical features, word embeddings).  
  - **Hidden layers:** multiple layers of neurons jo learned features extract karte hain.  
  - **Output layer:** final prediction produce karta hai (class scores, probability, regression output).

- Har **neuron**:
  - Apne inputs ka weighted sum + bias compute karta hai.  
  - Us sum ko nonlinear **activation function** (ReLU, sigmoid, tanh) se pass karta hai.

---

## 🔹 Forward Pass (Inference Intuition)

- Forward pass ka basic flow:  
  1. Input vector network ke input layer me jata hai.  
  2. Har layer: previous layer ka output × weight matrix + bias → activation function.  
  3. Last layer final output deti hai (for example, class probabilities via softmax).

- Important point: Network ke sare weights randomly start hote hain; training ke baad hi meaningful representations ban paate hain.

---

## 🔹 Training: Loss, Backpropagation, Optimizer

- **Loss function:** measure karta hai prediction ki quality (for example, cross‑entropy for classification, MSE for regression).
- **Backpropagation:** algorithm jo loss ke respect me sabhi weights ke gradients compute karta hai using chain rule, layer‑by‑layer backward pass. 
- **Optimizer:** gradient descent ka variant (SGD, Adam) jo gradients use karke weights update karta hai to loss kam ho.

High‑level training loop:

1. Batch of inputs + labels network ko dete hain.  
2. Forward pass → predictions.  
3. Loss compute hoti hai.  
4. Backpropagation se gradients nikalte hain.  
5. Optimizer se weights update hote hain.  
6. Ye process multiple epochs tak repeat hota hai.

---

## 🔹 Where Neural Networks Shine

- **Computer vision:** image classification, object detection, segmentation.
- **NLP:** sentiment analysis, translation, chatbots, LLMs.  
- **Time‑series:** forecasting, anomaly detection, sensor data analysis.

---

## 🔹 AI – Day 07 Takeaways

- Neural network = input → hidden layers of weighted sums + nonlinear activations → output layer, trained via loss + backprop + optimizer.
- Neural nets tab choose karte hain jab simple models (linear/logistic regression, trees) complex patterns capture nahi kar paate, specially unstructured data ke liye.
