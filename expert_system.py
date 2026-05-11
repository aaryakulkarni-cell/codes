from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB

# Training data
sentences = [
    "internet not working", "no internet connection", "wifi issue",
    "computer is slow", "system hanging", "slow performance",
    "forgot password", "reset password", "password issue",
    "printer not working", "printer problem", "cannot print",
    "software not opening", "application crash", "program not running"
]

labels = [
    "internet", "internet", "internet",
    "slow", "slow", "slow",
    "password", "password", "password",
    "printer", "printer", "printer",
    "software", "software", "software"
]

# Convert text to numbers
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(sentences)

# Train model
model = MultinomialNB()
model.fit(X, labels)

print("💻 Intelligent Help Desk Expert System")
print("Type 'exit' to quit\n")

while True:
    user_input = input("Describe your problem: ").lower()

    if user_input == "exit":
        print("Thank you! Have a nice day.")
        break

    # Convert input
    input_vec = vectorizer.transform([user_input])

    # Predict issue
    prediction = model.predict(input_vec)[0]

    # Expert system rules (knowledge base)
    if prediction == "internet":
        print("Expert Advice: Restart router and check cables. Contact ISP if issue continues.")

    elif prediction == "slow":
        print("Expert Advice: Close background apps, clean disk, and scan for viruses.")

    elif prediction == "password":
        print("Expert Advice: Use 'Forgot Password' option to reset your password.")

    elif prediction == "printer":
        print("Expert Advice: Check connection, refill paper, and restart printer.")

    elif prediction == "software":
        print("Expert Advice: Restart application or reinstall the software.")

    else:
        print("Expert Advice: Unable to diagnose. Contact technical support.")